/*
 * Conversion.h
 *
 *  Created on: 2018年8月30日
 *      Author: Administrator
 */

#ifndef CONVERSION_H_
#define CONVERSION_H_

class Conversion {
private:
	enum {
		Lbs_per_stn = 14
	};
	int stone;
	double pds_left;
	double pounds;
public:
	Conversion();
	Conversion(int lbs);
	explicit Conversion(double lbs);
	Conversion(int stn, double lbs);
	virtual ~Conversion();
	void test_conversion() const;
	void show_lbs() const;
	void show_stn() const;

	/**
	 * 转换函数
	 * 1.转换函数必须是类方法
	 * 2.转换函数不能指定返回类型
	 * 3.转换函数不能有参数
	 */
	operator int() const;
	operator double() const;
};

#endif /* CONVERSION_H_ */
