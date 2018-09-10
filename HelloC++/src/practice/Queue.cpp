/*
 * Queue.cpp
 *
 *  Created on: 2018Äê9ÔÂ10ÈÕ
 *      Author: Administrator
 */

#include "Queue.h"
#include <stdlib.h>

Queue::Queue(int qs) :
		qsize(qs) {
	// TODO Auto-generated constructor stub
	front = rear = 0;
	items = 0;
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
	Node *temp;
	while (front != 0) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isEmpty() const {
	return items == 0;
}

bool Queue::isFull() const {
	return items == qsize;
}

int Queue::queueCount() const {
	return items;
}

bool Queue::enqueue(const Item & item) {
	if (isFull())
		return false;
	Node * add = new Node;
	if (add == 0)
		return false;
	add->item = item;
	add->next = 0;
	items++;
	if (front == 0)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

bool Queue::dequeue(Item & item) {
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (item == 0)
		rear = 0;
	return true;
}

void Customer::set(long when) {
	process_time = rand() % 3 + 1;
	arrive = when;
}

const int MIN_PER_HR = 60;
bool new_customer(double x);

void Queue::test_queue() {

}

bool new_customer(double x) {
	return rand() * x / RAND_MAX < 1;
}
