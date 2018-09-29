/*
 * ClassTemplatePractice.cpp
 *
 *  Created on: 2018年9月26日
 *      Author: Administrator
 */

#ifndef PRACTICE_CLASSTEMPLATEPRACTICE_H_
#define PRACTICE_CLASSTEMPLATEPRACTICE_H_
#include<iostream>
#include <stdlib.h>
using std::cin;
using std::cout;
using std::endl;

template<typename T> void countT();
template<typename T> void reportT(T &);

template<class Type = bool>
class ClassTemplatePractice {
private:
	int hide;
	static const int count = 9;
public:
	int num = 8;
	ClassTemplatePractice(int num = 0) :
			num(num), hide(num) {
	}
	friend void counts();
	friend void reports(ClassTemplatePractice<Type> &);
	friend void countT<Type>();
	friend void reportT<ClassTemplatePractice<Type>>(
			ClassTemplatePractice<Type> &); //可以写成reportT<>(ClassTemplatePractice<Type> &);
	template<typename T, typename S> friend void show(T &, S &); //这里的typename不能和类的typename的'Type'相同
	void test_class_template_practice() const;
	void test_class_template_by_pointer() const;
	virtual ~ClassTemplatePractice() {
	}
};

template<typename Type = int, int LENGTH = 5>
class Stack {
private:
	enum {
		SIZE = 10
	};
	int stackSize;
	Type * items;
	int top;
public:
	int num = 8;
	explicit Stack(int ss = LENGTH);
	Stack(const Stack & st);
	bool isEmpty() {
		return top == 0;
	}
	bool isFull() {
		return top == stackSize;
	}
	bool push(const Type & item);
	bool pop(Type & item);
	Stack & operator=(const Stack & st);
	virtual ~Stack() {
		delete[] items;
	}
};

template<class Type, int LENGTH>
Stack<Type, LENGTH>::Stack(int ss) :
		stackSize(ss), top(0) {
	items = new Type[stackSize];
}

template<class Type, int LENGTH>
Stack<Type, LENGTH>::Stack(const Stack & st) {
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template<class T, int L> bool Stack<T, L>::push(const T & item) {
	if (top < stackSize) {
		items[top++] = item;
		return true;
	} else {
		return false;
	}
}

template<class T, int L> bool Stack<T, L>::pop(T & item) {
	if (top > 0) {
		item = items[--top];
		return true;
	} else {
		return false;
	}
}

template<class T, int L> Stack<T, L> & Stack<T, L>::operator =(
		const Stack<T, L> &st) {
	if (this == &st)
		return *this;
	delete[] items;
	stackSize = st.stackSize;
	top = st.top;
	items = new T[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
	return *this;
}

template<typename T>
void ClassTemplatePractice<T>::test_class_template_practice() const {
	Stack<std::string, 5> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order, " << endl
			<< "P to process a PO, or Q to quit." << endl;
	while (cin >> ch && std::toupper(ch) != 'Q') {
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch)) {
			cout << '\a';
			continue;
		}
		switch (ch) {
		case 'A':
		case 'a':
			cout << "Enter a PO number to add: ";
			cin >> po;
			if (st.isFull())
				cout << "stack already full" << endl;
			else
				st.push(po);
			break;
		case 'P':
		case 'p':
			if (st.isEmpty())
				cout << "stack already empty" << endl;
			else {
				st.pop(po);
				cout << "PO #" << po << " popped" << endl;
			}
			break;
		}
		cout << "Please enter A to add a purchase order, " << endl
				<< "P to process a PO, or Q to quit." << endl;
	}
	cout << "Bye" << endl;
}

template<typename T> void ClassTemplatePractice<T>::test_class_template_by_pointer() const {
	ClassTemplatePractice<bool> ctp(3);
	reportT(ctp);
	show(ctp, ctp);

	srand(time(0));
	cout << "Please enter stack size: ";
	int size;
	cin >> size;
	Stack<const char *, 5> st(size);
	const char* in[10] = { " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
			" 3: Betty Rocker", " 4: Ian Flagranti", " 5: Wolfgang Kibble",
			" 6: Portia Koop", " 7: Joy Almondo", " 8: Xaverie Paprika",
			" 9: Juan Moore", " 10: Misha Mache", };
	const char *out[10];
	int processed = 0;
	int next = 0;
	while (processed < 10) {
		if (st.isEmpty())
			st.push(in[next++]);
		else if (st.isFull())
			st.pop(out[processed++]);
		else if (rand() % 2 && next < 10)
			st.push(in[next++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < 10; i++)
		cout << out[i] << endl;
	cout << "Bye" << endl;
}

template<typename T> void countT() {
	cout << "template size: " << sizeof(T) << ";";
	cout << "template count: " << ClassTemplatePractice<T>::count << endl;
}

template<typename T> void reportT(T & t) {
	cout << "friend template report num: " << t.num << endl;
}

template<typename T, typename X> void show(T & t, X & x) {
	cout << "show hide:" << t.hide << "," << x.hide << endl;
}

#endif /* PRACTICE_CLASSTEMPLATEPRACTICE_H_ */
