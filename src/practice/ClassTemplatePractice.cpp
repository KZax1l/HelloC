/*
 * ClassTemplatePractice.cpp
 *
 *  Created on: 2018��9��26��
 *      Author: Administrator
 */

#include "ClassTemplatePractice.h"

void counts() {
	cout << "counts:" << ClassTemplatePractice<int>::count << endl;
}

void reports(ClassTemplatePractice<int> & ctp) {
	cout << "reports num:" << ctp.num << endl;
}
