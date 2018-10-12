/*
 * ExceptionPractice.h
 *
 *  Created on: 2018Äê10ÔÂ10ÈÕ
 *      Author: Administrator
 */

#ifndef PRACTICE_EXCEPTIONPRACTICE_H_
#define PRACTICE_EXCEPTIONPRACTICE_H_
#include <iostream>

class ExceptionPractice {
private:
	char word[40];
public:
	ExceptionPractice(const char * str = "demo");
	virtual ~ExceptionPractice();
	void exception_abort();
	void exception_code();
	void exception_try_catch();
	void exception_try_catch_by_object();
	void main() const;
	void show() const;
	void exception_stack();
};

class bad_hmean {
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) :
			v1(a), v2(b) {
	}
	void mesg();
};

inline void bad_hmean::mesg() {
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
			<< "invalid arguments: a = -b" << std::endl;
}

class bad_gmean {
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) :
			v1(a), v2(b) {
	}
	const char * mesg();
};

inline const char * bad_gmean::mesg() {
	return "gmean() arguments should be >= 0\n";
}

inline void ExceptionPractice::show() const {
	std::cout << "exception practice object " << word << " lives!" << std::endl;
}

#endif /* PRACTICE_EXCEPTIONPRACTICE_H_ */
