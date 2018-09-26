/*
 * ClassTemplatePractice.cpp
 *
 *  Created on: 2018年9月26日
 *      Author: Administrator
 */

#ifndef PRACTICE_CLASSTEMPLATEPRACTICE_H_
#define PRACTICE_CLASSTEMPLATEPRACTICE_H_
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template<class Type>
class ClassTemplatePractice {
private:
	enum {
		MAX = 10
	};
	Type items[MAX];
	int top;
public:
	ClassTemplatePractice();
	bool isEmpty() const;
	bool isFull() const;
	bool push(const Type & item);
	bool pop(Type & item);
	void test_class_template_practice() const;
	virtual ~ClassTemplatePractice();
};

template<class Type>
ClassTemplatePractice<Type>::ClassTemplatePractice() {
	top = 0;
}

template<class Type>
bool ClassTemplatePractice<Type>::isEmpty() const {
	return top == 0;
}

template<class Type> bool ClassTemplatePractice<Type>::isFull() const {
	return top == MAX;
}

template<class T> bool ClassTemplatePractice<T>::push(const T & item) {
	if (top < MAX) {
		items[top++] = item;
		return true;
	} else {
		return false;
	}
}

template<class T> bool ClassTemplatePractice<T>::pop(T & item) {
	if (top > 0) {
		item = items[--top];
		return true;
	} else {
		return false;
	}
}

template<typename T>
void ClassTemplatePractice<T>::test_class_template_practice() const {
	ClassTemplatePractice<std::string> st;
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

template<typename T>
ClassTemplatePractice<T>::~ClassTemplatePractice() {
	// TODO Auto-generated destructor stub
}

#endif /* PRACTICE_CLASSTEMPLATEPRACTICE_H_ */
