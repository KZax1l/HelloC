/*
 * StringPractice.cpp
 *
 *  Created on: 2018Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */

#include "StringPractice.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>

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

	get_file_line();
}

void StringPractice::get_file_line() const {
	using std::cerr;
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::_Ios_Openmode::_S_in;
	using std::_Ios_Openmode::_S_out;
	using std::string;
	ifstream fin;
	fin.open("README.md", _S_in | _S_out);
	if (!fin.is_open()) {
		cerr << "Can't open file. Bye." << endl;
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;

	getline(fin, item, ':');
	while (fin) {
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done" << endl;
	fin.close();
}
