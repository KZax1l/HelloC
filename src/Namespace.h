/*
 * Namespace.h
 *
 *  Created on: 2018Äê8ÔÂ23ÈÕ
 *      Author: Administrator
 */

#ifndef NAMESPACE_H_
#define NAMESPACE_H_

namespace pers {
const int LEN = 40;
struct Person {
	char fname[LEN];
	char lname[LEN];
};
void getPerson(Person &);
void showPerson(const Person &);
}

namespace debts {
using namespace pers;
struct Debt {
	Person name;
	double amount;
};
void getDebt(Debt &);
void showDebt(const Debt &);
double sumDebts(const Debt ar[], int n);
}

class Namespace {
public:
	void test_namespace();
};

#endif /* NAMESPACE_H_ */
