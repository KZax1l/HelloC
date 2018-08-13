//============================================================================
// Name        : HelloC++.cpp
// Author      : Zsago
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <time.h>
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
/**
 * 动态申请数组及释放
 */
void test_array_new() {
	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;
	cout << "p3[1]=" << p3[1] << endl;
	p3 += 1;
	cout << "now p3[0]=" << p3[0] << " and p3[1]=" << p3[1] << endl;
	p3 -= 1; //如果这里不回退的话，用delete释放是不是会释放不完全？
	delete[] p3;
}
/**
 * 数组的动态联编和静态联编
 */
void test_static_and_dynamic_binding() {
	int length;
	cout << "please input array length:" << endl;
	cin >> length;
	int staticArray[length];
	for (int i = 0; i < length; i++) {
		staticArray[i] = i + 1;
	}
	cout << "staticArray values:" << endl;
	for (int value : staticArray) {
		cout << value << "\t";
	}
	cout << endl;
	int* dynamicArray = new int[length];
	for (int i = 0; i < length; i++) {
		dynamicArray[i] = i + 10;
	}
	cout << "dynamicArray values:" << endl;
	for (int i = 0; i < length; i++) {
		cout << dynamicArray[i] << "\t";
	}
	cout << endl;
	delete[] dynamicArray;
}
/**
 * 延迟处理
 */
void test_waiting() {
	cout << "Enter the delay time in seconds:";
	int secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "starting\a" << endl;
	clock_t start = clock();
	while (clock() - start < delay) {
		if ((clock() - start) != CLOCKS_PER_SEC)
			continue;
		cout << "waiting..." << endl;
	}
	cout << "done \a" << endl;
}

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

//	test_address();

//	test_pointer();

//	test_use_new();

//	test_array_new();

//	test_static_and_dynamic_binding();

//	void test_char_pointer_delete();
//	test_char_pointer_delete();

	test_waiting();

	return 0;
}

void test_char_pointer_delete() {
	char* test_get_char_pointer(void);
	char* name;
	name = test_get_char_pointer();
	cout << name << " at " << (int*) name << endl;
	delete[] name;

	name = test_get_char_pointer();
	cout << name << " at " << (int*) name << endl;
	delete[] name;
}
/**
 * 使用动态内存返回值，但要注意释放内存
 */
char* test_get_char_pointer() {
	char temp[80];
	cout << "Enter last name:";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	return pn;
}
