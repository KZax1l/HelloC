/*
 * CoutPractice.h
 *
 *  Created on: 2018��11��1��
 *      Author: Administrator
 */

#ifndef PRACTICE_COUTPRACTICE_H_
#define PRACTICE_COUTPRACTICE_H_

class CoutPractice {
public:
	CoutPractice();
	void print_address() const; //��ӡ��ַ
	void print_by_put_write() const;
	void print_width() const; //�����ֶο��
	void print_fill() const; //����ֶ�
	void print_precision() const;
	void print_format() const; //���ø���������ʾ����
	void main() const;
	virtual ~CoutPractice();
};

#endif /* PRACTICE_COUTPRACTICE_H_ */
