/*
 * CoutPractice.cpp
 *
 *  Created on: 2018��11��1��
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
	cout.put(65); //��ӡ�ַ�'A'
	cout.put(66.3); //��ӡ�ַ�'B'
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

void CoutPractice::print_width() const {
	cout << '#';
	cout.width(12);
	cout << 12 << '#' << 24 << "#\n";
	int w = cout.width(30);
	cout << "default field width = " << w << ": \n";
	cout.width(5);
	cout << 'N' << ':';
	cout.width(8);
	cout << "N * N" << ": \n";
	for (long i = 1; i <= 100; i *= 10) {
		cout.width(5);
		cout << i << ": ";
		cout.width(8);
		cout << i * i << ": \n";
	}
}

void CoutPractice::print_format() const {
	using std::cin;
	using std::hex;
	using std::oct;
	cout << "Enter an integer: ";
	int n;
	cin >> n;
	cout << "n \t n*n\n";
	cout << n << " \t " << n * n << "(decimal)\n";
	cout << hex;
	cout << n << " \t ";
	cout << n * n << "(hexadecimal)\n";
	cout << oct << n << " \t " << n * n << "(octal)\n";
	dec(cout);
	cout << n << " \t " << n * n << "(decimal)\n";
}

void CoutPractice::main() const {
	print_address();
	print_by_put_write();
	print_width();
	print_format();
}

CoutPractice::~CoutPractice() {
	// TODO Auto-generated destructor stub
}

