/*
 * ExceptionPractice.cpp
 *
 *  Created on: 2018年10月10日
 *      Author: Administrator
 */

#include "ExceptionPractice.h"
#include <stdlib.h>
#include <float.h>
#include <math.h>

ExceptionPractice::ExceptionPractice() {
	// TODO Auto-generated constructor stub

}

ExceptionPractice::~ExceptionPractice() {
	// TODO Auto-generated destructor stub
}

/**
 * 异常处理之调用abort函数终止程序
 */
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

/**
 * 异常处理之返回错误码
 */
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

/**
 * 异常处理之异常捕获
 */
void ExceptionPractice::exception_try_catch() {
	using std::cin;
	using std::cout;
	using std::endl;
	double hmean_throw(double a, double b);

	double x, y, z;
	cout << "========== exception_try_catch ==========" << endl
			<< "Enter two numbers: ";
	while (cin >> x >> y) {
		try {
			z = hmean_throw(x, y);
		} catch (const char * s) {
			cout << s << endl;
			cout << "Enter a new pair of numbers: ";
			continue;
		}
		cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
		cout << "Enter next set of numbers <q to quit>: ";
	}
	cout << "Bye!" << endl;
}

void ExceptionPractice::exception_try_catch_by_object() {
	using std::cin;
	using std::cout;
	using std::endl;
	double hmean_throw_bad_hmean(double a, double b);
	double gmean_throw_bad_gmean(double a, double b);

	double x, y, z;
	cout << "========== exception_try_catch_by_object ==========" << endl
			<< "Enter two numbers: ";
	while (cin >> x >> y) {
		try {
			z = hmean_throw_bad_hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z
					<< endl;
			cout << "Geometric mean of " << x << " and " << y << " is "
					<< gmean_throw_bad_gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to quit>: ";
		} catch (bad_hmean & bg) {
			bg.mesg();
			cout << "Try again." << endl;
			continue;
		} catch (bad_gmean & hg) {
			cout << hg.mesg();
			cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "Sorry, you don't get to play any more." << endl;
			break;
		}
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

double hmean_throw(double a, double b) {
	using std::cout;
	using std::endl;
	if (a == -b) {
		throw "bad hmean() arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b);
}

double hmean_throw_bad_hmean(double a, double b) throw (bad_hmean) {
	using std::cout;
	using std::endl;
	if (a == -b) {
		throw bad_hmean(a, b);
	}
	return 2.0 * a * b / (a + b);
}

double gmean_throw_bad_gmean(double a, double b) throw (bad_gmean) {
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return sqrt(a * b);
}

void ExceptionPractice::main() const {
	ExceptionPractice ep;
	ep.exception_try_catch_by_object();
	ep.exception_try_catch();
	ep.exception_code();
	ep.exception_abort();
}
