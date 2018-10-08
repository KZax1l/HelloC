/*
 * ClassFriendPractice.h
 *
 *  Created on: 2018年9月30日
 *      Author: Administrator
 */

#ifndef PRACTICE_CLASSFRIENDPRACTICE_H_
#define PRACTICE_CLASSFRIENDPRACTICE_H_

class ClassFriendPractice {
public:
	ClassFriendPractice();
	virtual ~ClassFriendPractice();
	void main();
};

class Tv;

class RemoteTv {
private:
	int mode;
public:
	enum {
		TV, VCR
	};
	RemoteTv(int m = TV) :
			mode(m) {
	}
	bool volup(Tv & t);
	bool voldown(Tv & t);
	void onoff(Tv & t);
	void chanup(Tv & t);
	void chandown(Tv & t);
	void set_mode(Tv & t);
	void set_input(Tv & t);
	void set_chan(Tv & t, int c);
};

class Tv {
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;
public:
	friend void RemoteTv::set_chan(Tv & t, int c);
	friend class Remote; //这样做使整个Remote类成为Tv的友元，有时候只需某个方法成为友元时就显得多余了
	enum {
		Off, On
	};
	enum {
		MinVal, MaxVal = 20
	};
	enum {
		Antenna, Cable
	};
	enum {
		TV, VCR
	};
	Tv(int s = Off, int mc = 100) :
			state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(
					TV) {
	}
	void onoff() {
		state = (state == On) ? Off : On;
	}
	bool ison() const {
		return state == On;
	}
	bool volup();
	bool voldown();
	void chanup();
	void chandown();
	void set_mode() {
		mode = (mode == Antenna) ? Cable : Antenna;
	}
	void set_input() {
		input = (input == TV) ? VCR : TV;
	}
	void settings() const;
};

inline bool RemoteTv::volup(Tv & t) {
	return t.volup();
}

inline bool RemoteTv::voldown(Tv & t) {
	return t.voldown();
}

inline void RemoteTv::onoff(Tv & t) {
	t.onoff();
}

inline void RemoteTv::chanup(Tv & t) {
	t.chanup();
}

inline void RemoteTv::chandown(Tv & t) {
	t.chandown();
}

inline void RemoteTv::set_mode(Tv & t) {
	t.set_mode();
}

inline void RemoteTv::set_input(Tv & t) {
	t.set_input();
}

inline void RemoteTv::set_chan(Tv & t, int c) {
	t.channel = c;
}

class Remote {
private:
	int mode;
public:
	Remote(int m = Tv::TV) :
			mode(m) {
	}
	bool volup(Tv & t) {
		return t.volup();
	}
	bool voldown(Tv & t) {
		return t.voldown();
	}
	void onoff(Tv & t) {
		t.onoff();
	}
	void chanup(Tv & t) {
		t.chanup();
	}
	void chandown(Tv & t) {
		t.chandown();
	}
	void set_chan(Tv & t, int c) {
		t.channel = c;
	}
	void set_mode(Tv & t) {
		t.set_mode();
	}
	void set_input(Tv & t) {
		t.set_input();
	}
};

#endif /* PRACTICE_CLASSFRIENDPRACTICE_H_ */
