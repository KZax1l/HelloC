/*
 * Conversion.h
 *
 *  Created on: 2018��8��30��
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
};

#endif /* CONVERSION_H_ */
