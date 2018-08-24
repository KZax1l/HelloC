/*
 * Stock.cpp
 *
 *  Created on: 2018Äê8ÔÂ24ÈÕ
 *      Author: Administrator
 */

#include "Stock.h"
#include<iostream>
#include<string.h>

Stock::Stock() {
	// TODO Auto-generated constructor stub
	std::cout << "Default constructor called" << std::endl;
	strcpy(company, "no name");
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char *co, int n, double pr) {
	using std::cout;
	using std::endl;
	using std::cerr;
	std::cout << "Constructor using " << co << " called" << std::endl;
	strncpy(company, co, 29);
	company[29] = '\0';
	if (n < 0) {
		cerr << "Number of shares can't be negative; " << company
				<< " shares set to 0." << endl;
	} else {
		shares = n;
	}
	share_val = pr;
	set_tot();
}

Stock::~Stock() {
	// TODO Auto-generated destructor stub
	std::cout << "Bye, " << company << "!" << std::endl;
}

void Stock::test_stock() {
	using std::cout;
	using std::ios_base;
	using std::endl;
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Using constructors to create new objects" << endl;
	Stock stock1("NanoSmart", 12, 20.0);
	stock1.show();
	Stock stock2 = Stock("Boffo Objects", 2, 2.0);
	stock2.show();

	cout << "Assigning stock1 to stock2: " << endl;
	stock2 = stock1;
	cout << "Listing stock1 and stock2: " << endl;
	stock1.show();
	stock2.show();

	cout << "Using a constructor to reset an object" << endl;
	stock1 = Stock("Nifty Foods", 10, 50.0);
	cout << "Revised stock1: " << endl;
	stock1.show();
	cout << "Done" << endl;
}

void Stock::buy(int num, double price) {
	if (num < 0) {
		std::cerr << "Number of shares purchased can't be negative. "
				<< "Transaction is aborted." << std::endl;
	} else {
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(int num, double price) {
	using std::cerr;
	using std::endl;
	if (num < 0) {
		cerr << "Number of shares sold can't be negative. "
				<< "Transaction is aborted." << endl;
	} else if (num > shares) {
		cerr << "You can't sell more than you have! "
				<< "Transaction is aborted. " << endl;
	} else {
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price) {
	share_val = price;
	set_tot();
}

void Stock::show() {
	using std::cout;
	using std::endl;
	cout << "Company: " << company << " Shares: " << shares << endl
			<< " Share Price: $" << share_val << " Total Worth: $" << total_val
			<< endl;
}
