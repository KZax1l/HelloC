/*
 * CoutPractice.cpp
 *
 *  Created on: 2018年11月1日
 *      Author: Administrator
 */

#include "CoutPractice.h"
#include<iostream>
#include<string.h>
#include <math.h>
#include <iomanip>
using std::cout;
using std::endl;
using std::ios_base;

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

void CoutPractice::print_fill() const {
	cout.fill('*');
	const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper" };
	long bonus[2] = { 900, 1350 };
	for (int i = 0; i < 2; i++) {
		cout << staff[i] << ": $";
		cout.width(7);
		cout << bonus[i] << '\n';
	}
}

void CoutPractice::print_precision() const {
	float price1 = 20.40;
	float price2 = 1.9 + 8.0 / 9.0;
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";
	cout.precision(2);
	cout << "\"Furry Friends\" is $" << price1 << "!\n";
	cout << "\"Fiery Friends\" is $" << price2 << "!\n";
}

void CoutPractice::print_setf() const {
	int temperature = 63;
	cout << "Today's water temperature: ";
	cout.setf(ios_base::showpoint);
	cout << temperature << endl;
	cout << "For our programming friends, that's\n";
	cout << std::hex << temperature << endl;
	cout.setf(ios_base::uppercase);
	cout.setf(ios_base::showbase);
	cout << "or\n";
	cout << temperature << endl;
	cout << "How " << true << "! oops - How ";
	cout.setf(ios_base::boolalpha);
	cout << true << "!\n";
	cout << "----------" << endl;

	cout.fill(' ');
	cout.unsetf(ios_base::boolalpha);
	cout.setf(ios_base::dec, ios_base::basefield);
	cout.setf(ios_base::left, ios_base::adjustfield);
	cout.setf(ios_base::showpos);
	cout.setf(ios_base::showpoint);
	cout.precision(3);
	ios_base::fmtflags old = cout.setf(ios_base::scientific,
			ios_base::floatfield);
	cout << "Left Justification: \n";
	long n;
	for (n = 1; n <= 41; n += 10) {
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	cout.setf(ios_base::internal, ios_base::adjustfield);
	cout.setf(old, ios_base::floatfield);
	cout << "Internal Justification: \n";
	for (n = 1; n <= 41; n += 10) {
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
	cout.setf(ios_base::right, ios_base::adjustfield);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "Right Justification: \n";
	for (n = 1; n <= 41; n += 10) {
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}

	using std::left;
	using std::scientific;
	cout << left << scientific;
	cout << "Left Justification: \n";
	for (n = 1; n <= 41; n += 10) {
		cout.width(4);
		cout << n << "|";
		cout.width(12);
		cout << sqrt(double(n)) << "|\n";
	}
}

void CoutPractice::print_iomanip() const {
	using std::showpoint;
	using std::fixed;
	using std::right;
	using std::setw;
	using std::setfill;
	using std::setprecision;
	cout << showpoint << fixed << right;
	cout << setw(6) << "N" << setw(14) << "square root" << setw(15)
			<< "fourth root\n";
	double root;
	for (int n = 10; n <= 100; n += 10) {
		root = sqrt(double(n));
		cout << setw(6) << setfill('.') << n << setfill(' ') << setw(12)
				<< setprecision(3) << root << setw(14) << setprecision(4)
				<< sqrt(root) << endl;
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
	print_fill();
	print_precision();
	print_setf();
	print_iomanip();
	print_format();
}

CoutPractice::~CoutPractice() {
	// TODO Auto-generated destructor stub
}

