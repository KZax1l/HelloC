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

CustomString::CustomString() {
	// TODO Auto-generated constructor stub
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" default object created\n";
}

CustomString::CustomString(const char * s) {
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" default object created\n";
}

CustomString::CustomString(const CustomString & cs) {
	len = cs.len;
	str = cs.str; //由于str为指针，这样赋值的话，相当于指向了同一个地址，当调用delete释放后，这会出现问题
	num_strings++;
	cout << num_strings << ": \"" << str << "\" copy object created\n";
}

CustomString::~CustomString() {
	// TODO Auto-generated destructor stub
	cout << "\"" << str << "\" object deleted, ";
	--num_strings;
	cout << num_strings << " left\n";
	delete[] str;
}

std::ostream & operator<<(std::ostream & os, const CustomString & st) {
	os << st.str;
	return os;
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
	 */
	CustomString sailor = sports;
	cout << "sailor: " << sailor << endl;
	cout << "Assign one object to another: \n";
	CustomString knot;
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
