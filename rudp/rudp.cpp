// rudp.cpp - rudp

// Author : liyunteng <liyunteng@streamocean.com>
// Date   : 2019/07/28

// Copyright (C) 2019 StreamOcean, Inc.
// All rights reserved.

#include "rudp.hpp"
#include <arpa/inet.h>
#include <cassert>
#include <cerrno>
#include <cstring>

namespace rudp {
const int RUDP_SOCKET_SND_BUFF_SIZE  = 1024 * 1024 * 1;
const int RUDP_SOCKET_RECV_BUFF_SIZE = 1024 * 1024 * 1;

const static std::map<Rudp::rudp_error_e, std::string> errMap = {
    {Rudp::E_SUCCESS, "success"},
    {Rudp::E_FAILED, "failed"},
    {Rudp::E_CREATE_SOCKET, "create socket failed"},
    {Rudp::E_SEND_FAILED, "send failed"},
    {Rudp::E_RECV_FAILED, "recv failed"},
    {Rudp::E_BIND, "bind failed"},
    {Rudp::E_CONNECT, "connect failed"},
};

const char *
strerror(const Rudp::rudp_error_e err)
{
    auto it = errMap.find(err);
    if (it == errMap.end()) {
        return "unknown";
    }
    return it->second.c_str();
}

#define DEBUG(level, fmt, ...)              \
    do {                                    \
        if (m_log) {                        \
            m_log(level, fmt, __VA_ARGS__); \
        }                                   \
    } while (0)

size_t
Rudp::sendData(const void *data, const size_t data_size, const rudp_addr_t *const to_addr)
{
    if (m_sockfd == -1) {
        return E_CREATE_SOCKET;
    }

    struct sockaddr_in *to      = nullptr;
    socklen_t           socklen = sizeof(struct sockaddr_in);
    if (to_addr) {
        to = (struct sockaddr_in *)m_malloc(sizeof(struct sockaddr_in));
        assert(to != nullptr);
        memset(to, 0, sizeof(struct sockaddr_in));
        to->sin_family      = AF_INET;
        to->sin_addr.s_addr = inet_addr(to_addr->ip.c_str());
        to->sin_port        = htons(to_addr->port);
    }
    size_t send_size = 0;
    while (send_size < data_size) {
        ssize_t ds = sendto(m_sockfd, (uint8_t *)data + send_size, data_size - send_size, 0,
                            (struct sockaddr *)to, socklen);
        // size_t ds = send(m_sockfd, (uint8_t *)data+send_size, data_size - send_size, 0);
        if (ds <= 0) {
            DEBUG(0, "sendto failed: %s\n", std::strerror(errno));
            m_sendFailedPkgCount++;
            m_sendFailedByteCount += (data_size - send_size);
            if (to) {
                m_free(to);
            }
            return E_SEND_FAILED;
        }

        send_size += ds;
        m_sendPkgCount++;
        m_sendByteCount += ds;
    }
    if (to) {
        m_free(to);
    }
    return send_size;
}

size_t
Rudp::recvData(void *buff, const size_t buff_size, rudp_addr_t *from_addr)
{
    if (m_sockfd == -1) {
        return E_CREATE_SOCKET;
    }
    struct sockaddr_in *from = nullptr;
    socklen_t           len;
    if (from_addr) {
        from = (struct sockaddr_in *)m_malloc(sizeof(struct sockaddr_in));
    }

    ssize_t recv_size = recvfrom(m_sockfd, (uint8_t *)buff, buff_size, 0,
                                 (struct sockaddr *)from, &len);
    if (recv_size <= 0) {
        DEBUG(0, "recvfrom faile: %s", std::strerror(errno));
        m_recvFailedPkgCount++;
        if (from) {
            m_free(from);
        }
        return E_RECV_FAILED;
    }
    m_recvPkgCount++;
    m_recvByteCount += recv_size;
    if (from_addr) {
        from_addr->ip   = std::string(inet_ntoa(from->sin_addr));
        from_addr->port = ntohs(from->sin_port);
    }
    if (from) {
        m_free(from);
    }
    return recv_size;
}

Rudp::rudp_error_e
Rudp::createSocket(const rudp_addr_t *const my_addr, const rudp_addr_t *const peer_addr)
{
    m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (m_sockfd < 0) {
        DEBUG(0, "create socket failed: %s", std::strerror(errno));
        return E_CREATE_SOCKET;
    }
    if (my_addr) {
        m_my_sock_addr.sin_family      = AF_INET;
        m_my_sock_addr.sin_addr.s_addr = inet_addr(my_addr->ip.c_str());
        m_my_sock_addr.sin_port        = htons(my_addr->port);
        int rc = bind(m_sockfd, (struct sockaddr *)&m_my_sock_addr, sizeof(m_my_sock_addr));
        if (rc < 0) {

            DEBUG(0, "bind failed: %s", std::strerror(errno));

            return E_BIND;
        }
    }
#if 0
        if (peer_addr) {
            m_peer_sock_addr.sin_family = AF_INET;
            m_peer_sock_addr.sin_addr.s_addr = inet_addr(peer_addr->ip.c_str());
            m_peer_sock_addr.sin_port = htons(peer_addr->port);
            int rc = connect(m_sockfd, (struct sockaddr *)&m_peer_sock_addr, sizeof(m_peer_sock_addr));
            if (rc < 0) {

                    DEBUG(0, "connect failed: %s", std::strerror(errno));

                return E_CONNECT;
            }
        }
#endif

    return E_SUCCESS;
}

void
Rudp::dump(void)
{

    DEBUG(0, "module: 0X%02X\n", m_module);
    DEBUG(0, "sockfd: %d\n", m_sockfd);
    DEBUG(0, "mss: %u\n", m_mss);
    DEBUG(0, "mtu: %u\n", m_mtu);
    DEBUG(0, "rtt: %u\n", m_rtt);
    DEBUG(0, "rto: %u\n", m_rto);
    DEBUG(0, "srtt: %u\n", m_srtt);

    DEBUG(0, "sendPkg: %lu\n", m_sendPkgCount);
    DEBUG(0, "sendByte: %lu\n", m_sendByteCount);
    DEBUG(0, "recvPkg: %lu\n", m_recvPkgCount);
    DEBUG(0, "recvByte: %lu\n", m_recvByteCount);
    DEBUG(0, "lossPkg: %lu\n", m_lossPkgCount);
    DEBUG(0, "lossByte: %lu\n", m_lossByteCount);
    DEBUG(0, "sendFailedPkg: %lu\n", m_sendFailedPkgCount);
    DEBUG(0, "sendFailedByte: %lu\n", m_sendFailedByteCount);
}
Rudp::Rudp(uint8_t module, const rudp_addr_t *const my_addr, const rudp_addr_t *const peer_addr,
           rudp_malloc_handler malloc_handler, rudp_free_handler free_handler,
           rudp_log_handler log_handler)
    : m_module(module),
      m_sockfd(-1),
      m_my_addr(my_addr),
      m_peer_addr(peer_addr),
      m_malloc(malloc_handler),
      m_free(free_handler),
      m_log(log_handler)
{
    createSocket(my_addr, peer_addr);
}

Rudp::~Rudp() {}

}  // namespace rudp
