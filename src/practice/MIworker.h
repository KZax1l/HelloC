/*
 * MIworker.h
 *
 *  Created on: 2018Äê9ÔÂ21ÈÕ
 *      Author: Administrator
 */

#ifndef PRACTICE_MIWORKER_H_
#define PRACTICE_MIWORKER_H_
#include <string>

class MIworker {
private:
	std::string fullName;
	long id;
public:
	MIworker() :
			fullName("no one"), id(0L) {
	}
	MIworker(const std::string & s, long n) :
			fullName(s), id(n) {
	}
	virtual ~MIworker()=0;
	virtual void set();
	virtual void show() const;
	void test_mi_worker() const;
};

class Waiter: public MIworker {
private:
	int panache;
public:
	Waiter() :
			MIworker(), panache(0) {
	}
	Waiter(const std::string & s, long n, int p = 0) :
			MIworker(s, n), panache(p) {
	}
	Waiter(const MIworker & wk, int p = 0) :
			MIworker(wk), panache(p) {
	}
	void set();
	void show() const;
};

class Singer: public MIworker {
protected:
	enum {
		other, alto, contralto, soprano, bass, baritone, tenor
	};
	enum {
		Vtypes = 7
	};
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() :
			MIworker(), voice(other) {
	}
	Singer(const std::string & s, long n, int v = other) :
			MIworker(s, n), voice(v) {
	}
	Singer(const MIworker & wk, int v = other) :
			MIworker(wk), voice(v) {
	}
	void set();
	void show() const;
};

#endif /* PRACTICE_MIWORKER_H_ */
