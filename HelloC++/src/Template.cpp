/*
 * Template.cpp
 *
 *  Created on: 2018Äê8ÔÂ21ÈÕ
 *      Author: Administrator
 */

#include "Template.h"
#include <iostream>

template<typename Any> void Template::test_template_swap(Any & a, Any & b) {
	Any temp;
	temp = a;
	a = b;
	b = temp;
}
template<> void Template::test_template_swap<Template::job>(job &j1, job &j2) {
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}
void Template::test_template_show(Template::job &j) {
	cout << j.name << ":$" << j.salary << " on floor " << j.floor << endl;
}
void Template::test_template_swap_sample() {
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);
	int i = 10, j = 20;
	cout << "i,j = " << i << ", " << j << "." << endl;
	cout << "Using compiler-generated int swapper:" << endl;
	test_template_swap(i, j);
	cout << "Now i,j = " << i << "," << j << "." << endl;

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sideny Taffee", 78060.72, 9 };
	cout << "Before job swapping: " << endl;
	test_template_show(sue);
	test_template_show(sidney);
	test_template_swap(sue, sidney);
	cout << "After job swapping: " << endl;
	test_template_show(sue);
	test_template_show(sidney);
}
