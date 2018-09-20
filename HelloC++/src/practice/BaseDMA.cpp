/*
 * BaseDMA.cpp
 *
 *  Created on: 2018年9月20日
 *      Author: Administrator
 */

#include "BaseDMA.h"
#include <cstring>

BaseDMA::BaseDMA(const char *l, int r) {
	// TODO Auto-generated constructor stub
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & rs) {
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
}

BaseDMA::~BaseDMA() {
	// TODO Auto-generated destructor stub
	delete[] label;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & rs) {
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[std::strlen(rs.label) + 1];
	std::strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & rs) {
	os << "Label: " << rs.label << std::endl;
	os << "Rating: " << rs.rating << std::endl;
	return os;
}

void BaseDMA::test_Base_DMA() {
	using std::cout;
	using std::endl;

	BaseDMA shirt("Portabelly", 8);
	LacksDMA balloon("red", "Blimpo", 4);
	HasDMA map("Mercator", "Buffalo Keys", 5);
	cout << shirt << endl;
	cout << balloon << endl;
	cout << map << endl;
	LacksDMA balloon2(balloon);
	HasDMA map2;
	map2 = map;
	cout << balloon2 << endl;
	cout << map2 << endl;
}

LacksDMA::LacksDMA(const char *c, const char *l, int r) :
		BaseDMA(l, r) {
	std::strncpy(color, c, 39);
	color[39] = '\0';
}

LacksDMA::LacksDMA(const char *c, const BaseDMA & rs) :
		BaseDMA(rs) {
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LacksDMA & ls) {
	os << (const BaseDMA &) ls; //注意这里的强制转换
	os << "Color: " << ls.color << std::endl;
	return os;
}

HasDMA::HasDMA(const char *s, const char*l, int r) :
		BaseDMA(l, r) {
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

HasDMA::HasDMA(const char *s, const BaseDMA & rs) :
		BaseDMA(rs) {
	style = new char(std::strlen(s) + 1);
	std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA & hs) :
		BaseDMA(hs) {
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

HasDMA::~HasDMA() {
	delete[] style;
}

HasDMA & HasDMA::operator =(const HasDMA & hs) {
	if (this == &hs)
		return *this;
	BaseDMA::operator =(hs);
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & hs) {
	os << (const BaseDMA &) hs; //注意这里的强制转换
	os << "Style: " << hs.style << std::endl;
	return os;
}
