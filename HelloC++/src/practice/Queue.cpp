/*
 * Queue.cpp
 *
 *  Created on: 2018Äê9ÔÂ10ÈÕ
 *      Author: Administrator
 */

#include "Queue.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

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
	using std::cin;
	using std::cout;
	using std::endl;
	using std::ios_base;

	cout << "Case Study: Bank of Heather Automatic Teller" << endl;
	cout << "Enter maximum size of queue: ";
	int qs;
	cin >> qs;
	Queue line(qs);

	cout << "Enter the number of simulation hours: ";
	int hours;
	cin >> hours;
	long cyclelimit = MIN_PER_HR * hours;

	cout << "Enter the average number of customers per hour: ";
	double per_hour;
	cin >> per_hour;
	double min_per_cust;
	min_per_cust = MIN_PER_HR;

	Item temp;
	long turn_aways = 0;
	long customers = 0;
	long served = 0;
	long sum_line = 0;
	int wait_time = 0;
	long line_wait = 0;

	for (int cycle = 0; cycle < cyclelimit; cycle++) {
		if (new_customer(min_per_cust)) {
			if (line.isFull())
				turn_aways++;
			else {
				customers++;
				temp.set(cycle);
				line.enqueue(temp);
			}
		}
		if (wait_time <= 0 && !line.isEmpty()) {
			line.dequeue(temp);
			wait_time = temp.p_time();
			line_wait += cycle - temp.when();
			served++;
		}
		if (wait_time > 0)
			wait_time--;
		sum_line += line.queueCount();
	}
	if (customers > 0) {
		cout << "customers accepted: " << customers << endl;
		cout << "  customers served: " << served << endl;
		cout << "        turn_aways: " << turn_aways << endl;
		cout << "average queue size: ";
		cout.precision(2);
		cout.setf(ios_base::fixed, ios_base::floatfield);
		cout.setf(ios_base::showpoint);
		cout << (double) sum_line / cyclelimit << endl;
		cout << " average wait time: " << (double) line_wait / served
				<< " minutes" << endl;
	} else {
		cout << "No customers!" << endl;
	}
	cout << "Done!" << endl;
}

bool new_customer(double x) {
	return rand() * x / RAND_MAX < 1;
}
