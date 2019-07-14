// rudp.hpp - rudp

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/07/14

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.
#ifndef RUDP_HPP
#define RUDP_HPP
#include <cstdint>
#include <cstdlib>
#include <map>
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

namespace rudp {
    class Rudp {
    public:
        enum {
            RUDP_MAGIC = 0xF0F1,
            RUDP_VERSION_HEX = 0x01,
        };
        // used by arq
        typedef enum {
            RUDP_PRIORITY_EMERG  = 0x01,
            RUDP_PRIORITY_HIGH   = 0x02,
            RUDP_PRIORITY_NORMAL = 0x04,
            RUDP_PRIORITY_LOW    = 0x08,
        } rudp_priority_e;

        typedef enum {
            RUDP_MODULE_ARQ     = 0x01,
            RUDP_MODULE_FEC     = 0x02,
            RUDP_MODULE_FC      = 0x04,   // flow control
            RUDP_MODULE_PROFILE = 0x08,
            RUDP_MODULE_DEBUG   = 0xF0,
        } rudp_module_e;

        typedef enum {
            RUDP_TYPE_DATA  = 0x01,
            RUDP_TYPE_ARQ   = 0x02,
        } rudp_type_e;

        typedef struct __attribute__((__packed__)) {
            uint16_t magic;             /* RUDP_MAGIC */
            uint8_t version: 4;         /* RUDP_VERSION_HEX */
            uint8_t priority: 4;        /* rudp_priority_e */
            uint8_t offset;             /* data offset */

            uint8_t module;             /* rudp_module_e */
            uint8_t type;               /* rudp_type_e */
            uint16_t check_sum;         /* check sum */

            uint32_t idx;               /* sequence number */

            uint16_t len;               /* data len */
            uint16_t padding;
        } rudp_header_t;

        typedef enum {
            E_SUCCESS = 0x00,
            E_FAILED =  -0x01,
            E_CREATE_SOCKET = -0x02,
            E_SEND_FAILED = -0x03,
            E_RECV_FAILED = -0x04,
            E_BIND = -0x05,
            E_CONNECT = -0x06,
        } rudp_error_e;

        class _rudp_addr_t{
        public:
            std::string ip;
            int port;

            _rudp_addr_t() = default;
            _rudp_addr_t(const std::string i, const int p): ip(i), port(p){}
            _rudp_addr_t(const _rudp_addr_t &cp):ip(cp.ip), port(cp.port){}
            _rudp_addr_t(const _rudp_addr_t *cp): ip(cp->ip), port(cp->port){}
            _rudp_addr_t &operator=(const _rudp_addr_t &cp) {
                ip = cp.ip;
                port = cp.port;
                return *this;
            }
        };
        typedef _rudp_addr_t rudp_addr_t;

        typedef int (*rudp_log_handler)(int level, const char *fmt, ...);
        typedef void *(*rudp_malloc_handler)(size_t size);
        typedef void (*rudp_free_handler)(void *ptr);

    public:
        explicit Rudp(uint8_t module,
                      const rudp_addr_t * const my_addr = nullptr,
                      const rudp_addr_t * const peer_addr = nullptr,
                      rudp_malloc_handler malloc_handler=std::malloc,
                      rudp_free_handler free_handler = std::free,
                      rudp_log_handler log_handler = nullptr);
        ~Rudp();

        Rudp() = delete;
        Rudp(Rudp &) = delete;
        Rudp(const Rudp &) = delete;
        Rudp &operator=(Rudp &) = delete;
        Rudp &operator=(const Rudp&) = delete;

        size_t sendData(const void *data, const size_t data_size,
                        const rudp_addr_t * const to_addr = nullptr);
        size_t recvData(void *buff, const size_t buff_size,
                        rudp_addr_t *from_addr = nullptr);

        void dump(void);

    private:
        rudp_error_e createSocket(const rudp_addr_t * const my_addr = nullptr,
                                  const rudp_addr_t * const peer_addr = nullptr);

    private:
        uint8_t m_module;
        int m_sockfd;
        rudp_addr_t m_my_addr;
        rudp_addr_t m_peer_addr;
        sockaddr_in m_my_sock_addr;
        sockaddr_in m_peer_sock_addr;

        uint8_t m_mss;
        uint8_t m_mtu;
        uint8_t m_rtt;
        uint8_t m_rto;
        uint8_t m_srtt;

        uint64_t m_sendPkgCount;
        uint64_t m_sendByteCount;
        uint64_t m_recvPkgCount;
        uint64_t m_recvByteCount;
        uint64_t m_lossPkgCount;
        uint64_t m_lossByteCount;
        uint64_t m_sendFailedPkgCount;
        uint64_t m_sendFailedByteCount;
        uint64_t m_recvFailedPkgCount;
        uint64_t m_recvFailedByteCount;

        rudp_malloc_handler m_malloc = nullptr;
        rudp_free_handler m_free = nullptr;
        rudp_log_handler m_log = nullptr;
    };

    const char *strerror(const Rudp::rudp_error_e);
}

#endif
