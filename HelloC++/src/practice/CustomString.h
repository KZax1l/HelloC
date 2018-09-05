/*
 * CustomString.h
 *
 *  Created on: 2018Äê9ÔÂ5ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#ifndef PRACTICE_CUSTOMSTRING_H_
#define PRACTICE_CUSTOMSTRING_H_

class CustomString {
private:
	char *str;
	int len;
	static int num_strings;
public:
	CustomString();
	CustomString(const char *s);
	virtual ~CustomString();
	friend std::ostream & operator<<(std::ostream &os, const CustomString &st);
	void test_custom_string();
};

#endif /* PRACTICE_CUSTOMSTRING_H_ */
