// -*- compile-command: "clang++ -Wall -o 14copy_in_raii 14copy_in_raii.cpp -g
// -std=c++11 -lpthread"
// -*- 14copy_in_raii.cpp --

// Copyright (C) 2017 liyunteng
// Auther: liyunteng <li_yunteng@163.com>
// License: GPL
// Update time:  2017/01/02 20:22:15

// This program is free software; you can redistribute it and/or modify
// it under the terms and conditions of the GNU General Public License
// version 2,as published by the Free Software Foundation.

// This program is distributed in the hope it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.

// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation,
// Inc.,51 Franklin St - Fifth Floor, Boston,MA 02110-1301 USA.

// 1.复制RAII对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的
// copying行为
// 2.普遍而常见的RAII class copying行为是：抑制copying，实行引用计数

#include <iostream>
#include <memory>
#include <pthread.h>
#include <unistd.h>

using namespace std;

void
unlock(pthread_mutex_t *pm)
{
    pthread_mutex_unlock(pm);
    // cout << "unlock: " << pm << endl;
}
class Lock
{
public:
    explicit Lock(pthread_mutex_t *pm) : mutexPtr(pm, unlock)
    {
        pthread_mutex_lock(mutexPtr.get());
        // cout << "lock: " << pm << endl;
    }

private:
    Lock(const Lock &rhs);
    Lock &operator=(const Lock &rhs);
    shared_ptr<pthread_mutex_t> mutexPtr;
};

static int count          = 0;
static pthread_mutex_t sm = PTHREAD_MUTEX_INITIALIZER;
void *
thread_run(void *arg)
{
    while (1) {
        Lock l(&sm);
        if (count < 100) {
            cout << *(int *)arg << " count: " << count++ << endl;
        } else {
            break;
        }
    }

    return (void *)0;
}

int
main(void)
{
    // cout << "sm: " << &sm << endl;
    pthread_t pid1, pid2;
    int arg1, arg2;
    arg1 = 1;
    arg2 = 2;
    pthread_setconcurrency(2);
    pthread_create(&pid1, NULL, thread_run, (void *)&arg1);
    pthread_create(&pid2, NULL, thread_run, (void *)&arg2);
    pthread_join(pid1, NULL);
    pthread_join(pid2, NULL);
    return 0;
}
