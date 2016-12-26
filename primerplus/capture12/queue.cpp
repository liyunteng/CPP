/*
 * queue.cpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 17:51:42
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include "queue.hpp"
#include <cstdlib>

Queue::Queue(int qs):qsize(qs)
{
    front = rear = NULL;
    items = 0;
}

Queue::~Queue()
{
    Node *temp;
    while (front != NULL) {
	temp = front;
	front = front->next;
	delete temp;
    }
}

bool Queue::isempty() const const
{
    return items == 0;
}

bool Queue::isfull() const const
{
    return items == qsize;
}

int Queue::queuecount() const const
{
    return items;
}

bool Queue::enqueue(const Item & item)
{
    if (isfull())
	return false;

    Node *add = new Node;
    add->item = item;
    add->next = NULL;
    items++;
    if (front == NULL)
	front = add;
    else
	rear->next = add;

    rear = add;
    return true;
}

bool Queue::dequeue(Item & item)
{
    if (front == NULL)
	return false;

    item = front->item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
	rear = NULL;

    return true;
}

void Customer::set(long when)
{
    processtime = std::rand() % 3 + 1;
    arrive = when;
}
