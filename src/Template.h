/*
 * Template.h
 *
 *  Created on: 2018��8��21��
 *      Author: Administrator
 */

#ifndef TEMPLATE_H_
#define TEMPLATE_H_
using namespace std;

class Template {
	struct job {
		char name[40];
		double salary;
		int floor;
	};
	template<typename Any> void test_template_swap(Any & a, Any & b);
	void test_template_show(job &j);

//��Ҫ�ⲿ���õĺ���Ҫ��public���η�
public:
	void test_template_swap_sample();
};
//��ʾ���廯ģ�庯����Ҫ��ôд
template<> void Template::test_template_swap<Template::job>(job &j1, job &j2);

#endif /* TEMPLATE_H_ */
