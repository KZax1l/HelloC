/*
 * CoutPractice.h
 *
 *  Created on: 2018年11月1日
 *      Author: Administrator
 */

#ifndef PRACTICE_COUTPRACTICE_H_
#define PRACTICE_COUTPRACTICE_H_

class CoutPractice {
public:
	CoutPractice();
	void print_address() const; //打印地址
	void print_by_put_write() const;
	void print_width() const; //调整字段宽度
	void print_format() const;
	void main() const;
	virtual ~CoutPractice();
};

#endif /* PRACTICE_COUTPRACTICE_H_ */
