/*
 * Stock.h
 *
 *  Created on: 2018��8��24��
 *      Author: Administrator
 */

#ifndef STOCK_H_
#define STOCK_H_

class Stock {
private:
	char company[30];
	int shares;
	double share_val;
	double total_val;
	//��������
//	void set_tot() {
//		total_val = shares * share_val;
//	}
	void set_tot();
public:
	//���캯��
	Stock();
	Stock(const char *co, int n = 0, double pr = 0.0);
	//��������
	virtual ~Stock();
	void buy(int num, double price);
	void sell(int num, double price);
	void update(double price);
	//ʹ��const��֤���������޸Ķ���
	void show() const;
	void test_stock() const;
};
//��������
inline void Stock::set_tot() {
	total_val = shares * share_val;
}

#endif /* STOCK_H_ */
