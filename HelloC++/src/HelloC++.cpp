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
#include"Template.h"
#include"Newplace.h"
#include"Namespace.h"
#include"Stock.h"
#include"OperatorsOverloading.h"
#include"Conversion.h"
using namespace std;
typedef char* char_pointer;

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
/**
 * 输入字符串，并以特殊字符（哨兵字符）做停止输入标识
 * 会发现，这种输入方式会忽略空格和回车字符，
 * 而且即便输入了哨兵字符，也能继续输入，必须输入回车才行
 */
void test_cin_char_end_by_char() {
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:" << endl;
	cin.get(ch);
	while (ch != '#') {
		cout << ch;
		++count;
		cin.get(ch);
	}
	cout << endl << count << " characters read" << endl;
}
void test_cctype() {
#include <cctype>
	cout << "Enter text for analysis, and type @ to terminate input." << endl;
	char ch;
	int whitespace = 0; //记录输入的空格个数
	int digits = 0; //记录输入的数字个数
	int chars = 0; //记录输入的字符个数
	int punct = 0; //记录输入的标点符号的个数
	int others = 0;
	while ((ch = cin.get()) != '@') {
		if (isalpha(ch)) {
			chars++;
		} else if (isspace(ch)) {
			whitespace++;
		} else if (isdigit(ch)) {
			digits++;
		} else if (ispunct(ch)) {
			punct++;
		} else {
			others++;
		}
	}
	cout << chars << " letters, " << whitespace << " whitespace, " << digits
			<< " digits, " << punct << " punctuations, " << others << " others."
			<< endl;
}
int test_method_sum_arr(const int arr[], int count) {
	int total = 0;
	std::cout << arr << " = arr, ";
	std::cout << sizeof arr << " = sizeof arr" << std::endl;
	for (int i = 0; i < count; i++) {
		total += arr[i];
	}
	return total;
}
/**
 * 使用数组区间
 */
int test_method_sum_arr(const int* start, const int* end) {
	const int* pt;
	int total = 0;
	for (pt = start; pt != end; pt++) {
		total += *pt;
	}
	return total;
}
void test_method_sum_arr_sample() {
	const int ArSize = 8;
	int cookies[ArSize] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	std::cout << cookies << " = array address, ";
	std::cout << sizeof cookies << " = sizeof cookies" << std::endl;
	int sum = test_method_sum_arr(cookies, cookies + ArSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = test_method_sum_arr(cookies, cookies + 3);
	std::cout << "First three eaters ate " << sum << " cookies." << std::endl;
	sum = test_method_sum_arr(cookies + 4, cookies + 8);
	std::cout << "Last four eaters ate " << sum << " cookies." << std::endl;
}
struct sysop {
	char name[26];
	char quote[64];
	int used;
};
/**
 * 形参和返回值都是引用结构变量
 */
const sysop & test_struct_ref(sysop & sysopref) {
	cout << sysopref.name << " says:" << endl;
	cout << sysopref.quote << endl;
	sysopref.used++;
	return sysopref;
}
void test_struct_ref_sample() {
	sysop looper = { "Rick \"Fortran\" Looper", "I'm a goto kind of guy.", 0 };
	test_struct_ref(looper);
	cout << "Looper: " << looper.used << " use(s)" << endl;
	sysop copycast;
	copycast = test_struct_ref(looper);
	cout << "Looper: " << looper.used << " use(s)" << endl;
	cout << "Copycast: " << copycast.used << " use(s)" << endl;
	cout << "test_struct_ref(looper): " << test_struct_ref(looper).used
			<< " use(s)" << endl;
}

int main() {
	void test_char_pointer_delete();
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

//	test_address();

//	test_pointer();

//	test_use_new();

//	test_array_new();

//	test_static_and_dynamic_binding();

//	test_char_pointer_delete();

//	test_waiting();

//	test_cin_char_end_by_char();

//	test_cctype();

//	test_method_sum_arr_sample();

//	test_struct_ref_sample();

//	Template t;
//	t.test_template_swap_sample();

//	Newplace n;
//	n.test_newplace();

//	Namespace n;
//	n.test_namespace();

//	Stock s;
//	s.test_stock_top_val();

//	OperatorsOverloading o;
//	o.test_operators_overloading();

	Conversion c;
	c.test_conversion();

	return 0;
}

void test_char_pointer_delete() {
	char_pointer test_get_char_pointer(void);
	char_pointer name;
	name = test_get_char_pointer();
	cout << name << " at " << (int*) name << endl;
	delete[] name;

	name = test_get_char_pointer();
	cout << name << " at " << (int*) name << endl;
	delete[] name;
}
/**
 * 使用动态存储返回值，但要注意释放内存
 */
char_pointer test_get_char_pointer() {
	char temp[80];
	cout << "Enter last name:";
	cin >> temp;
	char_pointer pn = new char[strlen(temp) + 1];
	strcpy(pn, temp);
	cout << "pn address:" << (int*) pn << endl;
	return pn;
}
