#include "hangman.h"
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void Hangman::init() {
	ifstream input;
	input.open("hangman.txt");
	string word;
	while(input.good()) {
		getline(input,word);
		cout << word;
		char b;
		for(unsigned int i = 0; i < word.size(); i++) {
			b = word[i];
			string check = "";
			if(b != '\n') {
				check+= b;
			}
		}
		this->guesswords.push_back(word);
	}

	input.close();
}

Hangman::Hangman() {
	init();
}

void Hangman::randomWord() {
	srand(time(0) % 17);
	int randomPick = rand() % this->guesswords.size();
	this->guessword = this->guesswords[randomPick];
	for(unsigned int i = 0; i < guessword.size(); i++) {
		guess += "-";
	}
}

void Hangman::play() {
	randomWord();
	cout << guessword << ":hei";
	cout << "Welcome to hangman." << endl;
	int attempts = 5;
	bool win = false;
	char c;
	while(!win) {
		cout << guess << endl;
		cout << "Tries: " << attempts << endl;
		cout << "> ";
		cin >> c;
		if(guessword.find(c) != string::npos) {
			cout << "Woaah. You guessed right!" << endl;
			for(unsigned int i = 0; i < guessword.size(); ++i) {
				if((char)guessword[i] == c) {
					guess[i] = c;
				}
			}
		} else {
			cout << ":-( You guessed wrong." << endl;
			--attempts;
		}
		if(guess == guessword) {
			win = true;
		}
		if(attempts == 0) {
			break;
		}
	}
	if(win){
		cout << "Congratulations. You won!" << endl;
	} else {
		cout << "Your man was hung. You lose!" << endl;
	}
	char newGame;

	// Clearing game variables
	this->guessword = "";
	this->guess = "";
	cout << "Want to play again?(Y/N)";
	cin >> newGame;
	tolower(newGame);
	if(newGame == 'y') {
		return play();
	}
}
