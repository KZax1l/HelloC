/*
 * ExceptionPractice.h
 *
 *  Created on: 2018��10��10��
 *      Author: Administrator
 */

#ifndef PRACTICE_EXCEPTIONPRACTICE_H_
#define PRACTICE_EXCEPTIONPRACTICE_H_
#include <iostream>

class ExceptionPractice {
public:
	ExceptionPractice();
	virtual ~ExceptionPractice();
	void exception_abort();
	void exception_code();
	void exception_try_catch();
	void main() const;
};

#endif /* PRACTICE_EXCEPTIONPRACTICE_H_ */
