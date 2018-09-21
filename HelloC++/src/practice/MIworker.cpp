/*
 * MIworker.cpp
 *
 *  Created on: 2018Äê9ÔÂ21ÈÕ
 *      Author: Administrator
 */

#include "MIworker.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const int LIM = 4;

MIworker::~MIworker() {
	// TODO Auto-generated destructor stub
}

void MIworker::test_mi_worker() const {
	Waiter bob("Bob Apple", 314L, 5);
	Singer bev("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;
	MIworker * pw[LIM] = { &bob, &bev, &w_temp, &s_temp };
	int i;
	for (i = 2; i < LIM; i++)
		pw[i]->set();
	for (i = 0; i < LIM; i++) {
		pw[i]->show();
		cout << endl;
	}
}

void MIworker::set() {
	cout << "Enter worker's name: ";
	getline(cin, fullName);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void MIworker::show() const {
	cout << "Name: " << fullName << endl;
	cout << "Employee ID: " << id << endl;
}

char * Singer::pv[] = { "other", "alto", "contralto", "ssoprano", "bass",
		"baritone", "tenor" };

void Singer::set() {
	MIworker::set();
	cout << "Enter number for singer's vocal range: " << endl;
	int i;
	for (i = 0; i < Vtypes; i++) {
		cout << i << ": " << pv[i] << "		";
		if (i % 4 == 3)
			cout << endl;
	}
	if (i % 4 != 0)
		cout << endl;
	cin >> voice;
	while (cin.get() != '\n')
		continue;
}

void Singer::show() const {
	cout << "Category: singer" << endl;
	MIworker::show();
	cout << "Vocal range: " << pv[voice] << endl;
}

void Waiter::set() {
	MIworker::set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::show() const {
	cout << "Category: waiter" << endl;
	MIworker::show();
	cout << "Panache rating: " << panache << endl;
}
