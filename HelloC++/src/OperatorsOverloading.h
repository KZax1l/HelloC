/*
 * OperatorsOverloading.h
 *
 *  Created on: 2018��8��28��
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
	 * ��Ԫ�������ܼ�const?
	 */
	friend OperatorsOverloading operator*(double m,
			const OperatorsOverloading & t);
	/**
	 * ע�������ostream����Ĵ��κͷ���ֵ�����������ͣ��������ֵ�����������ͣ��ᱨ
	 * ' is protected within this context'�Ĵ���
	 */
	friend ostream & operator<<(ostream & os, const OperatorsOverloading & t);
	void show() const;
	void test_operators_overloading();
};

#endif /* OPERATORSOVERLOADING_H_ */
