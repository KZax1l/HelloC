/*
 * StringPractice.cpp
 *
 *  Created on: 2018Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */

#include "StringPractice.h"
#include<iostream>

StringPractice::StringPractice() {
	// TODO Auto-generated constructor stub

}

StringPractice::~StringPractice() {
	// TODO Auto-generated destructor stub
}

void StringPractice::main() const {
	using std::cout;
	using std::endl;
	using std::string;
	string one("Lottery Winner! ");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += " Oops!";
	cout << one << endl;
	two = "Sorry! That was";
	three[0] = 'P';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!" << endl;
	string six(alls + 6, alls + 10);
	cout << six << ", ";
	string seven(&five[6], &five[10]);
	cout << seven << "..." << endl;
}
