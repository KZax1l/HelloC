/*
 * ClassTemplatePractice.cpp
 *
 *  Created on: 2018Äê9ÔÂ26ÈÕ
 *      Author: Administrator
 */

#include "ClassTemplatePractice.h"

void counts() {
	cout << "counts:" << ClassTemplatePractice<int>::count << endl;
}

void reports(ClassTemplatePractice<int, 3> & ctp) {
	cout << "reports num:" << ctp.num << endl;
}
