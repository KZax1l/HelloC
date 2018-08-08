//============================================================================
// Name        : HelloC++.cpp
// Author      : Zsago
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void test_address() {
	int donuts = 3;
	double cpus = 4.5;

	cout << "donuts value:" << donuts;
	cout << " donuts address:" << &donuts << endl;

	cout << "cpus value:" << cpus;
	cout << " cpus address:" << &cpus << endl;
}
void test_pointer() {
	int updates = 6;
	int* p_updates = &updates;
	cout << "value updates=" << updates;
	cout << ",*p_updates=" << *p_updates << endl;
	cout << "address &updates=" << &updates;
	cout << ",p_updates=" << p_updates << endl;
	*p_updates += 1;
	cout << "now updates=" << updates << endl;
}
void test_use_new() {
	int* pt = new int;
	*pt = 1001;
	cout << "int value=" << *pt << ",location=" << pt << endl;

	double* pd = new double;
	*pd = 1000001.0;
	cout << "double value=" << *pd << ",location=" << pd << endl;

	cout << "sizeof pt:" << sizeof(pt) << ",sizeof *pt:" << sizeof(*pt) << endl;
	cout << "sizeof pd:" << sizeof(pd) << ",sizeof *pd:" << sizeof(*pd) << endl;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	test_address();
	test_pointer();
	test_use_new();
	return 0;
}
