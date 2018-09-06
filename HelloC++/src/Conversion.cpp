/*
 * Conversion.cpp
 *
 *  Created on: 2018��8��30��
 *      Author: Administrator
 */

#include "Conversion.h"
#include<iostream>
using std::cout;
using std::endl;

Conversion::Conversion() {
	// TODO Auto-generated constructor stub
	stone = pounds = pds_left = 0;
}

Conversion::Conversion(int lbs) {
	stone = lbs / Lbs_per_stn;
	pds_left = lbs % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Conversion::Conversion(double lbs) {
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

Conversion::Conversion(int stn, double lbs) {
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

void Conversion::test_conversion() const {
	void display(const Conversion &, int);

	//��Ӧ��ֻ��һ�����캯����ʵ�������������ĸ�ֵ��ʽҲֻ������һ�����εĹ��캯��
	Conversion pavarotti = 260;
	Conversion wolfe(285.7);
	Conversion taft(21.8);

	cout << "The tenor weighed ";
	pavarotti.show_stn();
	cout << "The detective weighed ";
	wolfe.show_stn();
	pavarotti = 265.8; //����ʹ����explicit�ؼ��ֹر���double���ε��Զ�ת�������������൱��Conversion(265)
	taft = 325;
	cout << "After dinner, the tenor weighed ";
	pavarotti.show_stn();
	cout << "After dinner, the President weighed ";
	taft.show_lbs();
	display(taft, 2);
	cout << "The wrestler weighed even more." << endl;
	display(422, 2);
	cout << "No stone left unearned" << endl;

	Conversion poppins(9, 2.8);
	double p_wt = poppins;
	cout << "Convert to double => ";
	cout << "Poppins: " << p_wt << " pounds." << endl;
	cout << "Convert to int => ";
	/*
	 * ע�������ǿת������������ͻᱨ'ambiguous overload'�Ķ����Դ���
	 * ��Ϊ��������֪�����ö����int����double��ת��
	 */
	cout << "Poppins: " << int(poppins) << " pounds." << endl;
}

void display(const Conversion & c, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Wow! ";
		c.show_stn();
	}
}

void Conversion::show_stn() const {
	cout << stone << " stone, " << pds_left << " pounds" << endl;
}

void Conversion::show_lbs() const {
	cout << pounds << " pounds" << endl;
}

Conversion::operator int() const {
	return int(pounds + 0.5);
}

Conversion::operator double() const {
	return pounds;
}

Conversion::~Conversion() {
	// TODO Auto-generated destructor stub
}
