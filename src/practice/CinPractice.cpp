/*
 * CinPractice.cpp
 *
 *  Created on: 2018Äê11ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "CinPractice.h"
#include <iostream>
#include <exception>
using std::cout;
using std::cin;
using std::endl;
using std::ios_base;

CinPractice::CinPractice() {
	// TODO Auto-generated constructor stub

}

void CinPractice::main() const {
	cin.exceptions(ios_base::failbit);
	cout << "Enter numbers: ";
	int sum = 0;
	int input;
	try {
		while (cin >> input) {
			sum += input;
		}
	} catch (ios_base::failure & bf) {
		cout << bf.what() << endl;
		cout << "0! the horror!\n";
	}
	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
}

CinPractice::~CinPractice() {
	// TODO Auto-generated destructor stub
}

