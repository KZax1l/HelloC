/*
 * RTTIPractice.cpp
 *
 *  Created on: 2018Äê10ÔÂ15ÈÕ
 *      Author: Administrator
 */

#include "RTTIPractice.h"
#include <stdlib.h>
#include <time.h>

RTTIPractice::RTTIPractice() {
	// TODO Auto-generated constructor stub

}

RTTIPractice::~RTTIPractice() {
	// TODO Auto-generated destructor stub
}

void RTTIPractice::main() const {
	srand(time(0));
	Grand * pg;
	Superb * ps;
	Grand * get_one();
	for (int i = 0; i < 5; i++) {
		pg = get_one();
		pg->speak();
		if (ps = dynamic_cast<Superb *>(pg)) {
			ps->say();
		}
	}
}

Grand * get_one() {
	Grand * p;
	switch (rand() % 3) {
	case 0:
		p = new Grand(rand() % 100);
		break;
	case 1:
		p = new Superb(rand() % 100);
		break;
	case 2:
		p = new Magnificent(rand() % 100, 'A' + rand() % 26);
		break;
	}
	return p;
}
