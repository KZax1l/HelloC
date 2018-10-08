/*
 * ClassFriendPractice.cpp
 *
 *  Created on: 2018Äê9ÔÂ30ÈÕ
 *      Author: Administrator
 */

#include "ClassFriendPractice.h"
#include <iostream>

ClassFriendPractice::ClassFriendPractice() {
	// TODO Auto-generated constructor stub

}

ClassFriendPractice::~ClassFriendPractice() {
	// TODO Auto-generated destructor stub
}

void ClassFriendPractice::main() {
	using std::cout;
	using std::endl;

	Tv s27;
	cout << "Initial settings for 27\" TV:" << endl;
	s27.settings();
	s27.onoff();
	s27.chanup();
	cout << endl << "Adjusted settings for 27\" TV:" << endl;
	s27.settings();

	RemoteTv grey;

	grey.set_chan(s27, 10);
	grey.volup(s27);
	grey.volup(s27);
	cout << endl << "27\" settings after using remote:" << endl;
	s27.settings();

	Tv s32(Tv::On);
	s32.set_mode();
	grey.set_chan(s32, 28);
	cout << endl << "32\" settings:" << endl;
	s32.settings();

	Remote r;
	cout << endl << "Remote mode -> " << r.get_mode() << endl;
	s32.buzz(r);
	cout << "Remote mode -> " << r.get_mode() << endl;
}

bool Tv::volup() {
	if (volume < MaxVal) {
		volume++;
		return true;
	} else {
		return false;
	}
}

bool Tv::voldown() {
	if (volume > MinVal) {
		volume--;
		return true;
	} else {
		return false;
	}
}

void Tv::chanup() {
	if (channel < maxchannel) {
		channel++;
	} else {
		channel = 1;
	}
}

void Tv::chandown() {
	if (channel > 1) {
		channel--;
	} else {
		channel = maxchannel;
	}
}

void Tv::settings() const {
	using std::cout;
	using std::endl;
	cout << "TV is " << (state == Off ? "Off" : "On") << endl;
	if (state == On) {
		cout << "Volume setting = " << volume << endl;
		cout << "Channel setting = " << channel << endl;
		cout << "Mode = " << (mode == Antenna ? "antenna" : "cable") << endl;
		cout << "Input = " << (input == TV ? "TV" : "VCR") << endl;
	}
}

