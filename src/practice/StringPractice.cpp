/*
 * StringPractice.cpp
 *
 *  Created on: 2018Äê10ÔÂ19ÈÕ
 *      Author: Administrator
 */

#include "StringPractice.h"
#include<iostream>
#include<fstream>
#include<stdlib.h>

StringPractice::StringPractice() {
	// TODO Auto-generated constructor stub

}

StringPractice::~StringPractice() {
	// TODO Auto-generated destructor stub
}

void StringPractice::main() const {
	using std::cout;
	using std::endl;
	using std::string;
	string one("Lottery Winner! ");
	cout << one << endl;
	string two(20, '$');
	cout << two << endl;
	string three(one);
	cout << three << endl;
	one += " Oops!";
	cout << one << endl;
	two = "Sorry! That was";
	three[0] = 'P';
	string four;
	four = two + three;
	cout << four << endl;
	char alls[] = "All's well that ends well";
	string five(alls, 20);
	cout << five << "!" << endl;
	string six(alls + 6, alls + 10);
	cout << six << ", ";
	string seven(&five[6], &five[10]);
	cout << seven << "..." << endl;

	get_file_line();
	string_find_game();
}

void StringPractice::get_file_line() const {
	using std::cerr;
	using std::cout;
	using std::endl;
	using std::ifstream;
	using std::_Ios_Openmode::_S_in;
	using std::_Ios_Openmode::_S_out;
	using std::string;
	ifstream fin;
	fin.open("README.md", _S_in | _S_out);
	if (!fin.is_open()) {
		cerr << "Can't open file. Bye." << endl;
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;

	getline(fin, item, ':');
	while (fin) {
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done" << endl;
	fin.close();
}

void StringPractice::string_find_game() const {
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;
	using std::string;

	const string word_list[26] = { "apiary", "beetle", "cereal", "danger",
			"ensign", "florid", "garage", "health", "insult", "jackal",
			"keeper", "loaner", "manage", "nonce", "onset", "plaid", "quilt",
			"remote", "stolid", "train", "useful", "valid", "whence", "xenon",
			"yearn", "zippy" };

	srand(time(0));
	char play;
	cout << "=================================" << endl;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;
	play = tolower(play);
	while (play == 'y') {
		string target = word_list[rand() % 26];
		int length = target.length();
		string attempt(length, '-');
		string bad_chars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length
				<< " letters, and you guess" << endl
				<< "one letter at a time. You get " << guesses
				<< " wrong guesses." << endl;
		cout << "Your word: " << attempt << endl;
		while (guesses > 0 && attempt != target) {
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if (bad_chars.find(letter) != string::npos
					|| attempt.find(letter) != string::npos) {
				cout << "You already guessed that. Try again." << endl;
				continue;
			}
			int loc = target.find(letter);
			if (loc == string::npos) {
				cout << "Oh,bad guess!" << endl;
				--guesses;
				bad_chars += letter;
			} else {
				cout << "Good guess!" << endl;
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while (loc != string::npos) {
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if (attempt != target) {
				if (bad_chars.length() > 0) {
					cout << "Bad choices: " << bad_chars << endl;
				}
				cout << guesses << "bad guesses left" << endl;
			}
		}
		if (guesses > 0) {
			cout << "That's right!" << endl;
		} else {
			cout << "Sorry, the word is " << target << "." << endl;
		}
		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye" << endl;
}
