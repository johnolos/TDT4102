#include <iostream>
#include <random>
#include "mastermind.h"
using namespace std;

const int SIZE = 4;
const int LETTERS = 6;

char randomChar() {
	int randNumber = rand() % LETTERS + 65;
	return (char)randNumber;
}

void readInput(char table[]) {
	int i = 0;
	char guessedChar;
	cout << "Guess " << SIZE << " chars from A to " << (char)(65 + LETTERS-1) << ": " << endl;
	while (i < SIZE) {
		cout << (i+1) << ": ";
		cin >> guessedChar;
		guessedChar = toupper(guessedChar);
		cout << endl;
		if ((int)guessedChar >= ((int)'A') && (int)guessedChar <= ((int)'A'+LETTERS-1)) {
			table[i] = guessedChar;
			i++;
		}
	}
}

int checkCharacters(char table[], char guess[]) {
	int correct = 0;
	char copy[SIZE];
	for(int i = 0; i < SIZE; i++){
		copy[i] = table[i];
	}
	for(int i = 0; i < SIZE; i++) {
		char c = guess[i];
		for(int j = 0; j < SIZE; j++) {
			if(c == copy[j]) {
				correct++;
				copy[j] = 'x';
				break;
			}
		}
	}
	return correct;
}

int checkCharactersAndPosition(char table[], char guess[]) {
	int correct = 0;
	for(int i = 0; i < SIZE; i++) {
		if(table[i] == guess[i])
			correct++;
	}
	return correct;
}

void printCode(char tab[]) {
	cout << "[ ";
	for(int i = 0; i < SIZE; i++) {
		cout << tab[i] << " ";
	}
	cout << "]" << endl;
}

void playMastermind() {
	char play = 'Y';
	while (play == 'Y') {
		// Establish tables for the game
		char code[SIZE];
		char guess[SIZE];
		// Fill code with random characters
		for(int i = 0; i < SIZE; i++) {
			code[i] = randomChar();
		}
		//printCode(code); Cheat
		cout << "Welcome to Mastermind." << endl;
		int correctPositions = 0;
		int attempts = 0;
		while(correctPositions < SIZE) {
			readInput(guess);
			cout << "Your guess was ";
			printCode(guess);
			cout << endl;
			correctPositions = checkCharactersAndPosition(code, guess);
			cout << "You had " << checkCharacters(code, guess) << " correctly guessed letters." << endl;
			cout << "You had " << correctPositions << " of guessed letters in correct place." << endl;
			attempts++;
		}
		cout << "You used " << attempts << " attempts to guess the code." << endl;
		cout << "Do you want to play again? (Y/N): ";
		cin >> play;
		cout << endl;
		play = toupper(play);
	}
	
}