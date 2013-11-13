#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include "hangman.h"

using namespace std;

// Exercise 6-1a
void writeToFile() {
	ofstream myfile;
	myfile.open("output.txt");
	string str;
	cout << "Continue writing until finished, then type quit:" << endl;
	cin >> str;
	while(str.compare("quit")) {
		myfile << str << endl;
		cin >> str;
	}
	myfile.close();
}

// Exercise 6-1b
void readFromFileToAnother(){
	ifstream original;
	ofstream copy;
	original.open("output.txt");
	copy.open("copy.txt");
	string readline;
	int a = 1;
	while(original.good()) {
		getline(original,readline);
		copy << a << " " << readline << endl;
		++a;
	}
	original.close();
	copy.close();
}

//Exercise 6-2
void getStatistics() {
	ifstream input;
	ofstream statistics;
	map<char,int> mapped;
	input.open("info.txt");
	char c;
	int num = 0;
	while(input.good()) {
		c = tolower(input.get());
		if(isalpha(c)) {
			++mapped[c];
		}
		++num;
	}
	input.close();
	statistics.open("statistic.txt");
	statistics << "Character statistics:" << endl;
	statistics << "Total number of characters: " << num << endl;

	int i = 1;
	for(std::map<char,int>::iterator it = mapped.begin(); it != mapped.end(); ++it) {
		statistics << it->first << ":" << it->second << "\t\t";
		if((i % 4) == 0) {
			statistics << endl;
		}
		++i;
	}
	statistics.close();
}

// Exercise 6-3
void countWords() {
	ifstream input;
	ofstream output;
	map<string, int> strings;
	input.open("info.txt");
	vector<char> word;
	string str, longest;
	int lenght = 0, numberOfWords = 0, sumOfWordLengths = 0;
	char c;

	while(input.good()) {
		c = tolower(input.get());
		if(isalpha(c)) {
			word.push_back(c);
		} else if ( c != ' ' && c != '-') {
			continue;
		} else {
			for(unsigned int i = 0; i < word.size(); ++i) {
				str+= word[i];
			}
			++strings[str];
			if(str.length() > lenght) {
				longest = str;
				lenght = str.length();
			}
			sumOfWordLengths += str.size();
			str = "";
			word.clear();
			++numberOfWords;
		}
	}
	input.close();
	output.open("textstats.txt");
	output << "Text statistics:" << endl;
	output << "Number of words: " << numberOfWords << endl;
	output << "Longest word: " + longest << endl;
	output << "Average word length: " << (sumOfWordLengths / numberOfWords) << endl;
	for(std::map<string,int>::iterator it = strings.begin(); it != strings.end(); ++it) {
		output << it->first << ": " << it->second << endl;
	}
	output.close();
}



int main() {
	//writeToFile(); // Works

	//readFromFileToAnother(); // Works

	//getStatistics(); // Works

	//countWords(); // Works

	/*
	 * Added some couts to see whats happending.
	 * getline doesnt remove a "newline" element at end of string.
	 * I haven't been sucessfully removing it myself. It is then
	 * hard to guess a word without a character. Everything else works
	 * as expected.
	 */
	//Hangman * hangman = new Hangman();
	//hangman->play();
	return 0;
}


