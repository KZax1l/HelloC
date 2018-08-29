/*
 * OperatorsOverloading.cpp
 *
 *  Created on: 2018年8月28日
 *      Author: Administrator
 */

#include "OperatorsOverloading.h"

OperatorsOverloading::OperatorsOverloading() {
	// TODO Auto-generated constructor stub
	hours = minutes = 0;
}

OperatorsOverloading::OperatorsOverloading(int h, int m) {
	// TODO Auto-generated constructor stub
	hours = h;
	minutes = m;
}

void OperatorsOverloading::addMin(int m) {
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void OperatorsOverloading::addHr(int h) {
	hours += h;
}

void OperatorsOverloading::reset(int h, int m) {
	hours = h;
	minutes = m;
}

/**
 * 这里返回值不能是引用类型，因为返回的是一个局部对象变量，该函数调用完后，
 * 这个局部对象变量就会被回收，那么返回的引用对象就会是这个被回收而不再存在的对象
 */
OperatorsOverloading OperatorsOverloading::operator +(
		const OperatorsOverloading & t) const {
	OperatorsOverloading temp;
	temp.minutes = minutes + t.minutes;
	temp.hours = hours + t.hours + temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}

/**
 * 非成员函数
 */
OperatorsOverloading operator*(double m, const OperatorsOverloading & t) {
	OperatorsOverloading temp;
	long total_min = t.hours * 60 + t.minutes;
	temp.hours = total_min / 60;
	temp.minutes = total_min % 60;
	return temp;
}

ostream & operator<<(ostream & os, const OperatorsOverloading & t) {
	os << t.hours << " hours, " << t.minutes << " minutes";
	return os;
}

void OperatorsOverloading::show() const {
	std::cout << hours << " hours, " << minutes << " minutes";
}

void OperatorsOverloading::test_operators_overloading() {
	using std::cout;
	using std::endl;
	OperatorsOverloading planning;
	OperatorsOverloading coding(2, 40);
	OperatorsOverloading fixing(5, 55);
	OperatorsOverloading total;

	cout << "planning time = ";
	planning.show();
	cout << endl;

	cout << "coding time = ";
	coding.show();
	cout << endl;

	cout << "fixing time = ";
	fixing.show();
	cout << endl;

	total = coding + fixing;
	cout << "coding + fixing = ";
	total.show();
	cout << endl;

	OperatorsOverloading morefixing(3, 28);
	cout << "more fixing time = ";
	morefixing.show();
	cout << endl;
	total = morefixing.operator +(total);
	cout << "morefixing.operator+(total) = ";
	total.show();
	cout << endl;

	total = operator *(2.75, morefixing);
	cout << "operator*(2.75, morefixing) = ";
	total.show();
	cout << endl;

	total = 2.75 * morefixing;
	cout << "2.75 * morefixing = ";
	total.show();
	cout << endl;

	OperatorsOverloading trip(1, 10);
	cout << "Trip time: " << trip << " (Tuesday) " << endl;
}

OperatorsOverloading::~OperatorsOverloading() {
	// TODO Auto-generated destructor stub
}

