/*
 * Newplace.cpp
 *
 *  Created on: 2018��8��23��
 *      Author: Administrator
 */

#include "Newplace.h"
#include<iostream>

void Newplace::test_newplace() {
	char buffer[BUF];
	double *pd1, *pd2;
	int i;
	cout << "Calling new and placement new:" << endl;
	pd1 = new double[N];
	pd2 = new (buffer) double[N];
	for (i = 0; i < N; i++) {
		pd2[i] = pd1[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer addresses:" << endl << " heap: " << pd1 << " static: "
			<< (void *) buffer << endl;
	cout << "Buffer contents:" << endl;
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	cout << endl << "Calling new and placement new a second time:" << endl;
	double *pd3, *pd4;
	pd3 = new double[N];
	pd4 = new (buffer) double[N];
	for (i = 0; i < N; i++) {
		pd4[i] = pd3[i] = 1000 + 20.0 * i;
	}
	cout << "Buffer contents:" << endl;
	for (i = 0; i < N; i++) {
		cout << pd3[i] << " at " << &pd3[i] << "; ";
		cout << pd4[i] << " at " << &pd4[i] << endl;
	}

	cout << endl << "Calling new and placement new a third time:" << endl;
	delete[] pd1;
	pd1 = new double[N];
	pd2 = new (buffer + N * sizeof(double)) double[N];
	for (i = 0; i < N; i++) {
		cout << pd1[i] << " at " << &pd1[i] << "; ";
		cout << pd2[i] << " at " << &pd2[i] << endl;
	}
	delete[] pd1;
	delete[] pd3;
}
