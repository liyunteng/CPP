/*
 * queue.hpp --
 *
 * Copyright (C) 2016 liyunteng
 * Auther: liyunteng <li_yunteng@163.com>
 * License: GPL
 * Update time:  2016/11/16 17:51:46
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

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Customer {
  public:
    Customer() {
	arrive = processtime = 0;
    } virtual ~ Customer() {
    }

    void set(long when);
    long when() const {
	return arrive;
    } int ptime() const {
	return processtime;
  } private:
    long arrive;
    int processtime;
};

typedef Customer Item;

class Queue {
  public:
    Queue(int qs = Q_SIZE);
     virtual ~ Queue();

    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const Item & item);
    bool dequeue(Item & item);

  private:
     Queue(const Queue &):qsize(0) {
    } Queue & operator=(const Queue &) {
	return *this;
    }

  private:
    struct Node {
	Item item;
	struct Node *next;
    };
    enum { Q_SIZE = 10 };

    Node *front;
    Node *rear;
    int items;
    const int qsize;
};


#endif
