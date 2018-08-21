/*
 * Template.h
 *
 *  Created on: 2018年8月21日
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

//需要外部调用的函数要加public修饰符
public:
	void test_template_swap_sample();
};
//显示具体化模板函数需要这么写
template<> void Template::test_template_swap<Template::job>(job &j1, job &j2);

#endif /* TEMPLATE_H_ */
