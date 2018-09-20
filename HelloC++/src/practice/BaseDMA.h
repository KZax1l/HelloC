/*
 * BaseDMA.h
 *
 *  Created on: 2018Äê9ÔÂ20ÈÕ
 *      Author: Administrator
 */

#ifndef PRACTICE_BASEDMA_H_
#define PRACTICE_BASEDMA_H_
#include <iostream>

class BaseDMA {
private:
	char *label;
	int rating;
public:
	BaseDMA(const char *l = "null", int r = 0);
	BaseDMA(const BaseDMA & rs);
	virtual ~BaseDMA();
	BaseDMA & operator=(const BaseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
	void test_Base_DMA();
};

class LacksDMA: public BaseDMA {
private:
	enum {
		COL_LEN
	};
	char color[COL_LEN];
public:
	LacksDMA(const char *c = "blank", const char *l = "null", int r = 0);
	LacksDMA(const char *c, const BaseDMA & rs);
	friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);
};

class HasDMA: public BaseDMA {
private:
	char *style;
public:
	HasDMA(const char *s = "none", const char *l = "null", int r = 0);
	HasDMA(const char *s, const BaseDMA & rs);
	HasDMA(const HasDMA & hs);
	~HasDMA();
	HasDMA & operator=(const HasDMA & hs);
	friend std::ostream & operator<<(std::ostream & os, const HasDMA & hs);
};

#endif /* PRACTICE_BASEDMA_H_ */
