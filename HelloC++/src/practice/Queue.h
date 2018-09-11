/*
 * Queue.h
 *
 *  Created on: 2018��9��10��
 *      Author: Administrator
 */

#ifndef PRACTICE_QUEUE_H_
#define PRACTICE_QUEUE_H_

class Customer {
private:
	long arrive;
	int process_time;
public:
	Customer() {
		arrive = process_time = 0;
	}
	void set(long when);
	long when() const {
		return arrive;
	}
	int p_time() const {
		return process_time;
	}
	bool operator==(int value) {
		return arrive == value && process_time == value;
	}
};

typedef Customer Item;

class Queue {
private:
	struct Node {
		Item item;
		struct Node *next;
	};
	enum {
		Q_SIZE = 10
	};
	Node *front;
	Node *rear;
	int items;
	const int qsize; //const���ݳ�Ա������ִ�е����캯����ǰ���г�ʼ��
	Queue(const Queue & q) :
			qsize(0) { //ʹ�ó�ʼ���б��ʼ��const���ݳ�Ա
	}
	Queue & operator=(const Queue & q) {
		return *this;
	}
public:
	Queue(int qs = Q_SIZE);
	virtual ~Queue();
	bool isEmpty() const;
	bool isFull() const;
	int queueCount() const;
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
	void test_queue();
};

#endif /* PRACTICE_QUEUE_H_ */
