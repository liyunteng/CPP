/*
 * test.cpp - test
 *
 * Author : liyunteng <liyunteng@streamocean.com>
 * Date   : 2019/07/14
 *
 * Copyright (C) 2019 StreamOcean, Inc.
 * All rights reserved.
 */
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "rudp.hpp"
using namespace rudp;
int log(int level, const char *fmt, ...)
{
    (void)level;
    int n = 0;
    va_list ap;
    va_start(ap, fmt);
    n += vprintf(fmt, ap);
    va_end(ap);
    return n;
}

void test1()
{
    Rudp::rudp_header_t h;
    h.magic = Rudp::RUDP_MAGIC;
    h.version = Rudp::RUDP_VERSION_HEX;
    h.priority = Rudp::RUDP_PRIORITY_NORMAL;
    h.module = Rudp::RUDP_MODULE_ARQ | Rudp::RUDP_MODULE_FC | Rudp::RUDP_MODULE_DEBUG | Rudp::RUDP_MODULE_PROFILE;
    h.type = Rudp::RUDP_TYPE_DATA;
    h.check_sum = 0;
    h.idx = 0;
    h.len = 100;

    printf("%lu\n", sizeof(Rudp::rudp_header_t));
}

int main(void)
{
    Rudp::rudp_addr_t my_addr;
    my_addr.ip = "127.0.0.1";
    my_addr.port = 12345;
    Rudp::rudp_addr_t to_addr;
    to_addr.ip = "127.0.0.1";
    to_addr.port = 12346;
    Rudp *r = new Rudp(Rudp::RUDP_MODULE_ARQ | Rudp::RUDP_MODULE_DEBUG, &my_addr, &to_addr, malloc, free, log);
    char x = '1';
    char buf[64][128];
    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 126; j++) {
            buf[i][j] = x;
        }
        buf[i][126] = '\n';
        buf[i][127] = '\0';
        x++;
    }
    size_t size = 0;

    for (int i = 0; i < 64; i++)
    {
        size = r->sendData(&buf[i], 128);
    }
    Rudp::rudp_addr_t from;
    char a[512] = {0};
    if ((size = r->recvData(&a, sizeof(a), &from) > 0)) {
        printf("recvfrom: %s:%d\n%s\n",
               from.ip.c_str(),
               from.port, a);
    }

    r->dump();
    return 0;
}

// Local Variables:
// compile-command: "clang++ -Wall -o test test.cpp -g rudp.cpp -v "
// End:
