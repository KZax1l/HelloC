/*
 * CustomString.h
 *
 *  Created on: 2018Äê9ÔÂ5ÈÕ
 *      Author: Administrator
 */

#include<iostream>
#ifndef PRACTICE_CUSTOMSTRING_H_
#define PRACTICE_CUSTOMSTRING_H_
using std::istream;
using std::ostream;

class CustomString {
private:
	char *str;
	int len;
	static int num_strings;
public:
	static const int CINLIM = 80;
	CustomString();
	CustomString(const char *s);
	CustomString(const CustomString & cs);
	virtual ~CustomString();
	friend std::ostream & operator<<(std::ostream & os,
			const CustomString & st);
	void test_custom_string();
	CustomString & operator=(const CustomString & cs);
	int length() const {
		return len;
	}
	CustomString & operator=(const char *);
	friend bool operator<(const CustomString & cs, const CustomString & s);
	friend bool operator>(const CustomString & cs, const CustomString & s);
	friend bool operator==(const CustomString & cs, const CustomString & s);
	friend istream operator>>(const istream & is, const CustomString & cs);
	char & operator[](int i);
	const char & operator[](int i) const;
	static int howMany();
};

#endif /* PRACTICE_CUSTOMSTRING_H_ */
