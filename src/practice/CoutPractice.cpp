/*
 * CoutPractice.cpp
 *
 *  Created on: 2018��11��1��
 *      Author: Administrator
 */

#include "CoutPractice.h"
#include<iostream>

CoutPractice::CoutPractice() {
	// TODO Auto-generated constructor stub

}

void CoutPractice::print_address() const {
	using std::cout;
	using std::endl;
	int eggs = 12;
	char * amount = "dozen";
	cout << &eggs << endl;
	cout << amount << endl;
	cout << (void *) amount << endl;
}
void CoutPractice::main() const {
	print_address();
}

CoutPractice::~CoutPractice() {
	// TODO Auto-generated destructor stub
}

