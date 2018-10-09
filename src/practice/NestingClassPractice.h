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

#endif /* PRACTICE_NESTINGCLASSPRACTICE_H_ */
