/*
 * CoutPractice.cpp
 *
 *  Created on: 2018年11月1日
 *      Author: Administrator
 */

#include "CoutPractice.h"
#include<iostream>
#include<string.h>
using std::cout;
using std::endl;

CoutPractice::CoutPractice() {
	// TODO Auto-generated constructor stub

}

void CoutPractice::print_address() const {
	int eggs = 12;
	char * amount = "dozen";
	cout << &eggs << endl;
	cout << amount << endl;
	cout << (void *) amount << endl;
}

void CoutPractice::print_by_put_write() const {
	cout.put('W');
	cout.put('i').put('t');
	cout.put(65); //打印字符'A'
	cout.put(66.3); //打印字符'B'
	cout << endl;
	const char * state1 = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = strlen(state2);
	cout << "Increasing loop index: " << endl;
	int i;
	for (i = 1; i <= len; i++) {
		cout.write(state2, i);
		cout << endl;
	}
	cout << "Exceeding string length: " << endl;
	cout.write(state2, len + 7) << endl;
}

void CoutPractice::main() const {
	print_address();
	print_by_put_write();
}

CoutPractice::~CoutPractice() {
	// TODO Auto-generated destructor stub
}

