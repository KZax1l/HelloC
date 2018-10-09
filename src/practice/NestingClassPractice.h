/*
 * NestingClassPractice.h
 *
 *  Created on: 2018Äê10ÔÂ9ÈÕ
 *      Author: Administrator
 */

#ifndef PRACTICE_NESTINGCLASSPRACTICE_H_
#define PRACTICE_NESTINGCLASSPRACTICE_H_

template<typename Item>
class NestingClassPractice {
private:
	enum {
		Q_SIZE = 10
	};
	class Node {
	public:
		Item item;
		Node * next;
		Node(const Item & i) :
				item(i), next(0) {
		}
	};
	Node * front;
	Node * rear;
	int items;
	const int qsize;
	NestingClassPractice(const NestingClassPractice & ncp) :
			qsize(0) {
	}
	NestingClassPractice & operator=(const NestingClassPractice & ncp) {
		return *this;
	}
public:
	NestingClassPractice(int qs = Q_SIZE);
	virtual ~NestingClassPractice();
	bool is_empty() const {
		return items == 0;
	}
	bool is_full() const {
		return items == qsize;
	}
	int queue_count() const {
		return items;
	}
	bool enqueue(const Item & item);
	bool dequeue(Item & item);
};

template<typename Item>
NestingClassPractice<Item>::NestingClassPractice(int qs) :
		qsize(qs) {
	front = rear = 0;
	items = 0;
}

template<typename Item>
NestingClassPractice<Item>::~NestingClassPractice() {
	Node * temp;
	while (front != 0) {
		temp = front;
		front = front->next;
		delete temp;
	}
}

template<typename Item>
bool NestingClassPractice<Item>::enqueue(const Item & item) {
	if (is_full())
		return false;
	Node * add = new Node(item);
	if (add == 0)
		return false;
	items++;
	if (front == 0)
		front = add;
	else
		rear->next = add;
	rear = add;
	return true;
}

template<typename Item>
bool NestingClassPractice<Item>::dequeue(Item & item) {
	if (front == 0)
		return false;
	item = front->item;
	items--;
	Node * temp = front;
	front = front->next;
	delete temp;
	if (items == 0)
		rear = 0;
	return true;
}

#endif /* PRACTICE_NESTINGCLASSPRACTICE_H_ */
