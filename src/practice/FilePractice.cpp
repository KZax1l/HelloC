/*
 * FilePractice.cpp
 *
 *  Created on: 2018Äê11ÔÂ8ÈÕ
 *      Author: Administrator
 */

#include "FilePractice.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;

FilePractice::FilePractice() {
	// TODO Auto-generated constructor stub

}

void FilePractice::main() const {
	string filename;
	cout << "Enter name for a new file: " << endl;
	cin >> filename;
	ofstream fout(filename.c_str());
	fout << "For your eyes only!\n";
	cout << "Enter your secret number: ";
	float secret;
	cin >> secret;
	fout << "Your secret number is " << secret << endl;
	fout.close();
	ifstream fin(filename);
	cout << "Here are the contents of " << filename << ": \n";
	char ch;
	while (fin.get(ch))
		cout << ch;
	cout << "Done\n";
	fin.close();
}

FilePractice::~FilePractice() {
	// TODO Auto-generated destructor stub
}

