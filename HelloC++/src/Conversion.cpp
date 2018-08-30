/*
 * Conversion.cpp
 *
 *  Created on: 2018年8月30日
 *      Author: Administrator
 */

#include "Conversion.h"
#include<iostream>
using std::cout;
using std::endl;

Conversion::Conversion() {
	// TODO Auto-generated constructor stub
	stone = pounds = pds_left = 0;
}

Conversion::Conversion(double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Conversion::Conversion(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

void Conversion::test_conversion() const {
	void display(const Conversion &, int);

	Conversion pavarotti = 260;
	Conversion wolfe(285.7);
	Conversion taft(21.8);

	cout << "The tenor weighed ";
	pavarotti.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	pavarotti = 265.8; //对应于只有一个构造函数的实例化，但这样的赋值方式也只适用于一个传参的构造函数
	taft = 325;
	cout << "After dinner, the tenor weighed ";
	pavarotti.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more." << endl;
	display(422, 2);
	cout << "No stone left unearned" << endl;
}

void display(const Conversion & c, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Wow! ";
		c.show_stn();
	}
}

void Conversion::show_stn() const {
	cout << stone << " stone, " << pds_left << " pounds" << endl;
}

void Conversion::show_lbs() const {
	cout << pounds << " pounds" << endl;
}

Conversion::~Conversion() {
	// TODO Auto-generated destructor stub
}

