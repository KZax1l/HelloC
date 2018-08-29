/*
 * OperatorsOverloading.h
 *
 *  Created on: 2018年8月28日
 *      Author: Administrator
 */

#ifndef OPERATORSOVERLOADING_H_
#define OPERATORSOVERLOADING_H_
#include "iostream"
using std::ostream;

class OperatorsOverloading {
private:
	int hours;
	int minutes;
public:
	OperatorsOverloading();
	OperatorsOverloading(int h, int m = 0);
	virtual ~OperatorsOverloading();
	void addMin(int m);
	void addHr(int h);
	void reset(int h = 0, int m = 0);
	OperatorsOverloading operator+(const OperatorsOverloading & t) const;
	/**
	 * 友元函数不能加const?
	 */
	friend OperatorsOverloading operator*(double m,
			const OperatorsOverloading & t);
	/**
	 * 注意这里的ostream对象的传参和返回值都是引用类型，如果返回值不是引用类型，会报
	 * ' is protected within this context'的错误
	 */
	friend ostream & operator<<(ostream & os, const OperatorsOverloading & t);
	void show() const;
	void test_operators_overloading();
};

#endif /* OPERATORSOVERLOADING_H_ */
