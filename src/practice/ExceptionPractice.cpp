/*
 * ExceptionPractice.cpp
 *
 *  Created on: 2018Äê10ÔÂ10ÈÕ
 *      Author: Administrator
 */

#include "ExceptionPractice.h"
#include <stdlib.h>
#include <float.h>

ExceptionPractice::ExceptionPractice() {
	// TODO Auto-generated constructor stub

}

ExceptionPractice::~ExceptionPractice() {
	// TODO Auto-generated destructor stub
}

void ExceptionPractice::exception_abort() {
	using std::cin;
	using std::cout;
	using std::endl;
	double hmean(double a, double b);

	double x, y, z;
	cout << "========== exception_abort ==========" << endl
			<< "Enter two numbers: ";
	while (cin >> x >> y) {
		z = hmean(x, y);
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye!" << endl;
}

void ExceptionPractice::exception_code() {
	using std::cin;
	using std::cout;
	using std::endl;
	double hmean(double a, double b, double * ans);

	double x, y, z;
	cout << "========== exception_code ==========" << endl
			<< "Enter two numbers: ";
	while (cin >> x >> y) {
		if (hmean(x, y, &z)) {
			cout << "Harmonic mean of " << x << " and " << y << " is " << z
					<< endl;
		} else {
			cout << "One value should not be the negative "
					<< "of the other - try again." << endl;
		}
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye!" << endl;
}

double hmean(double a, double b) {
	using std::cout;
	using std::endl;
	if (a == -b) {
		cout << "untenable arguments to hmean()" << endl;
		abort(); // or use 'exit()' method
	}
	return 2.0 * a * b / (a + b);
}

bool hmean(double a, double b, double * ans) {
	using std::cout;
	using std::endl;
	if (a == -b) {
		*ans = DBL_MAX;
		return false;
	} else {
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

void ExceptionPractice::main() const {
	ExceptionPractice ep;
	ep.exception_code();
	ep.exception_abort();
}
