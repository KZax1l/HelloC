/*
 * Stock.cpp
 *
 *  Created on: 2018年8月24日
 *      Author: Administrator
 */

#include "Stock.h"

Stock::Stock() {
	// TODO Auto-generated constructor stub
	std::cout << "Default constructor called" << std::endl;
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}
Stock::Stock(const char *co, int n, double pr) {
	using std::cout;
	using std::endl;
	using std::cerr;
	std::cout << "Constructor using " << co << " called" << std::endl;
	company = co;
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

void Stock::test_stock_show() const {
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

void Stock::show() const {
	using std::cout;
	using std::endl;
	cout << "Company: " << company << " Shares: " << shares << endl
			<< " Share Price: $" << share_val << " Total Worth: $" << total_val
			<< endl;
}

const Stock & Stock::top_val(const Stock & s) const {
	//this是该对象的地址，要得到对象当然要使用*
	return s.total_val > total_val ? s : *this;
}

void Stock::test_stock_top_val() const {
	using std::cout;
	using std::ios_base;
	using std::endl;

	const int STKS = 4;
	Stock stocks[STKS] = { Stock(
			"Dunkelmeister, Dostoyevsky, and Delderfield Construction", 12,
			20.0), Stock("Boffo Objects", 200, 2.0), Stock(
			"Monolithic Obelisks", 130, 3.25) };
	cout.precision(2);
	cout.setf(ios_base::fixed, ios_base::floatfield);
	cout.setf(ios_base::showpoint);

	cout << "Stock holdings:" << endl;
	int st;
	for (st = 0; st < STKS; st++) {
		stocks[st].show();
	}
	Stock top = stocks[0];
	for (st = 1; st < STKS; st++) {
		top = top.top_val(stocks[st]);
	}
	cout << endl << "Most valuable holding:" << endl;
	top.show();
}
