#ifndef HANGMAN_H
#define HANGMAN_H

#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Hangman {
private:
	string guessword, guess;
	vector<string> guesswords;
	void init();
public:
	Hangman();
	void randomWord();
	void play();
};

#endif
