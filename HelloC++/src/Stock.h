/*
 * Stock.h
 *
 *  Created on: 2018年8月24日
 *      Author: Administrator
 */

#ifndef STOCK_H_
#define STOCK_H_
#include<string.h>
#include<iostream>

class Stock {
private:
	std::string company;
	int shares;
	double share_val;
	double total_val;
	//内联函数
//	void set_tot() {
//		total_val = shares * share_val;
//	}
	void set_tot();
public:
	//构造函数
	Stock();
	Stock(const char *co, int n = 0, double pr = 0.0);
	//析构函数
	virtual ~Stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	//使用const保证函数不会修改对象
	void show() const;
	void test_stock_show() const;
	double total() const {
		return total_val;
	}
	const Stock & top_val(const Stock & s) const;
	void test_stock_top_val() const;
};
//内联函数
inline void Stock::set_tot() {
	total_val = shares * share_val;
}

#endif /* STOCK_H_ */
