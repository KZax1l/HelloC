/*
 * AcctABC.h
 *
 *  Created on: 2018年9月19日
 *      Author: Administrator
 */

#ifndef PRACTICE_ACCTABC_H_
#define PRACTICE_ACCTABC_H_
#include <iostream>

class AcctABC {
private:
	enum {
		MAX = 35
	};
	char fullName[MAX];
	long acctNum;
	double balance;
protected:
	const char * FullName() const {
		return fullName;
	}
	long AcctNum() const {
		return acctNum;
	}
	std::ios_base::fmtflags SetFormat() const;
public:
	AcctABC(const char *s = "Nullbody", long an = -1, double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt)=0; //声明纯虚函数指出该类是一个抽象基类
	double Balance() const {
		return balance;
	}
	virtual void ViewAcct() const=0; //声明纯虚函数指出该类是一个抽象基类
	virtual ~AcctABC();
};

class Brass: public AcctABC {
public:
	Brass(const char *s = "Nullbody", long an = -1, double bal = 0.0) :
			AcctABC(s, an, bal) { //基类的成员初始化列表
	}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass();
};

class BrassPlus: public AcctABC {
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const char *s = "Nullbody", long an = -1, double bal = 0.0,
			double ml = 500, double r = 0.10);
	BrassPlus(const Brass & ba, double ml = 500, double r = 0.1);
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m) {
		maxLoan = m;
	}
	void ResetRate(double r) {
		rate = r;
	}
	void ResetOwes() {
		owesBank = 0;
	}
};

#endif /* PRACTICE_ACCTABC_H_ */
