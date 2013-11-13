#include <iostream>
#include <string>
#include <random>
#include "mastermind.h"
using namespace std;

int phoneNumbers[][7];

// Part 1b
void printArray(int list [], int length) {
	for(int i = 0; i < length; i++) {
		cout << list[i] << endl;
	}
}

// Part 2b
void printArray(int table[][7], int length) {
	//cout << "MON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN" << endl;
	string weekdays[7] = {"MON","TUE","WED","THU", "FRI","SAT","SUN"};
	for(int i = 0; i < length; i++) {
		for(int j = 0;j < 7; j++) {
			cout << weekdays[j] << ": " << table[i][j] << " ";
		}
		cout << endl;
	}
}

// Part 2c
void randomizeList(int table[][7], int length, int antallOppringninger) {
	for(int i = 0; i < antallOppringninger; i++) {
		int row = rand() % length;
		int cell = rand() % 7;
		table[row][cell]++;
	}
}

// Part 2d
int countCalls(int table[][7], int length, int day) {
	int calls = 0;
	for(int i = 0; i < length; i++) {
		calls += table[i][day];
	}
	return calls;
}

int main() {
	// Part 1a
	int phoneNumbers [5];
	phoneNumbers[0] = 12345678;
	phoneNumbers[1] = 13245678;
	phoneNumbers[2] = 12435678;
	phoneNumbers[3] = 12346578;
	phoneNumbers[4] = 12345769;
	printArray(phoneNumbers, 5);

	// Part 2a
	int exTable[2][7];
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 7; j++) {
			exTable[i][j] = rand() % 6;
		}
	}
	randomizeList(exTable, 2, 100);
	printArray(exTable, 2);
	cout << countCalls(exTable, 2, 5);
	
	
	
	// Mastermind - Part 3
	playMastermind();
	
	
	int a;
	cin >> a;
	return 0;
}