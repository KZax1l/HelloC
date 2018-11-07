/*
 * CinPractice.cpp
 *
 *  Created on: 2018Äê11ÔÂ7ÈÕ
 *      Author: Administrator
 */

#include "CinPractice.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

CinPractice::CinPractice() {
	// TODO Auto-generated constructor stub

}

void CinPractice::main() const {
	cout << "Enter numbers: ";
	int sum = 0;
	int input;
	while (cin >> input) {
		sum += input;
	}
	cout << "Last value entered = " << input << endl;
	cout << "Sum = " << sum << endl;
}

CinPractice::~CinPractice() {
	// TODO Auto-generated destructor stub
}

