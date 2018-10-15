/*
 * RTTIPractice.h
 *
 *  Created on: 2018年10月15日
 *      Author: Administrator
 */

#ifndef PRACTICE_RTTIPRACTICE_H_
#define PRACTICE_RTTIPRACTICE_H_
#include <iostream>

using std::cout;
using std::endl;

class RTTIPractice {
public:
	RTTIPractice();
	virtual ~RTTIPractice();
	void main() const;
};

class Grand {
private:
	int hold;
public:
	Grand(int h = 0) :
			hold(h) {
	}
	virtual void speak() const {
		cout << "I am grand class!" << endl;
	}
	virtual int value() const {
		return hold;
	}
	virtual ~Grand() { // 加上这个，以免警告"but non-virtual destructor"
	}
};

class Superb: public Grand {
public:
	Superb(int h = 0) :
			Grand(h) {
	}
	void speak() const {
		cout << "I am a superb class!!" << endl;
	}
	virtual void say() const {
		cout << "I hold the superb value of " << value() << "!" << endl;
	}
};

class Magnificent: public Superb {
private:
	char ch;
public:
	Magnificent(int h = 0, char c = 'A') :
			Superb(h), ch(c) {
	}
	void speak() const {
		cout << "I am a magnificent class!!!" << endl;
	}
	void say() const {
		cout << "I hold the character " << ch << " and the integer " << value()
				<< "!" << endl;
	}
};

#endif /* PRACTICE_RTTIPRACTICE_H_ */
