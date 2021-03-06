/*
 * CustomString.cpp
 *
 *  Created on: 2018年9月5日
 *      Author: Administrator
 */

#include "CustomString.h"
#include <cstring>
using std::cout;

int CustomString::num_strings = 0;

int CustomString::howMany() {
	return num_strings;
}

CustomString::CustomString() {
	// TODO Auto-generated constructor stub
	len = 4;
	/**
	 * 空指针可以用0或NULL
	 * 比起使用'new char[1]'来说更简便，而且，
	 * delete(无论是带中括号还是不带中括号)可以用于空指针
	 */
	str = 0;
	num_strings++;
}

CustomString::CustomString(const char * s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
}

CustomString::CustomString(const CustomString & cs) {
	len = cs.len;
	str = new char[len + 1];
	std::strcpy(str, cs.str);
	num_strings++;
}

CustomString::~CustomString() {
	// TODO Auto-generated destructor stub
	--num_strings;
	delete[] str;
}

std::ostream & operator<<(std::ostream & os, const CustomString & st) {
	os << st.str;
	return os;
}

CustomString & CustomString::operator =(const CustomString & cs) {
	using std::endl;
	if (this == &cs) {
		cout << "same object, return *this" << endl;
		return *this;
	}
	cout << "copy string" << endl;
	delete[] str;
	len = cs.len;
	str = new char(len + 1);
	std::strcpy(str, cs.str);
	return *this;
}

CustomString & CustomString::operator =(const char * s) {
	delete[] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

char & CustomString::operator [](int i) {
	return str[i];
}

const char & CustomString::operator [](int i) const {
	return str[i];
}

bool operator<(const CustomString & cs, const CustomString & s) {
	return std::strcmp(cs.str, s.str) < 0;
}

bool operator>(const CustomString & cs, const CustomString & s) {
	return s.str < cs.str;
}

bool operator==(const CustomString & cs, const CustomString & s) {
	return std::strcmp(cs.str, s.str) == 0;
}

istream & operator>>(istream & is, CustomString & cs) {
	char temp[CustomString::CINLIM];
	is.get(temp, CustomString::CINLIM);
	if (is)
		cs = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}

void CustomString::test_custom_string() {
	using std::endl;
	void callme1(CustomString &);
	void callme2(CustomString);
	CustomString headline1("Celery Stalks at Midnight");
	CustomString headline2("Lettuce Prey");
	CustomString sports("Spinach Leaves Bow1 for Dolars");
	cout << "headline1: " << headline1 << endl;
	cout << "headline2: " << headline2 << endl;
	cout << "sports: " << sports << endl;
	callme1(headline1);
	cout << "headline1: " << headline1 << endl;
	callme2(headline2);
	cout << "headline2: " << headline2 << endl;
	cout << "Initialize one object to another: \n";
	/*
	 * 这种赋值方式调用的是复制构造函数，复制构造函数的原型通常如下：
	 * Class_name(const Class_name &);
	 * 即这里的赋值等价于"CustomString sailor = CustomString(sports)"
	 * 初始化对象时，并不一定会使用类的赋值操作符
	 */
	CustomString sailor = sports;
	cout << "sailor: " << sailor << endl;
	cout << "Assign one object to another: \n";
	CustomString knot;
	/**
	 * 这里会调用类的赋值操作符，类的赋值操作符重载原型如下：
	 * Class_name & Class_name::operator=(const Class_name &);
	 * 将已有的对象赋给另一对象时，将使用类重载的赋值操作符
	 * 这里由于knot已经创建了对象，而再进行赋值，就会调用类的赋值操作符
	 */
	knot = headline1;
	cout << "knot: " << knot << endl;
	cout << "End of main()\n";
}

void callme1(CustomString & rsb) {
	cout << "String passed by reference: \n";
	cout << "    \"" << rsb << "\"\n";
}

/*
 * 这里传参不是
 */
void callme2(CustomString sb) {
	cout << "String passed by value: \n";
	cout << "    \"" << sb << "\"\n";
}
