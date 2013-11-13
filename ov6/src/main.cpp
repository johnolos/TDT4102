#import <cstring>
#import "iostream.h"
#import "ctype.h"
#import "minesweeper.h"
#import "Matrix.h"

void getInput(char* str, int max) {
	str = new char[max];
	cout << "Type " << max << " characters:" << endl;
	cin >> str;
	while(strlen(str) > max) {
		cout << "Try again:" << endl;
		cin >> str;
	}
	cout << str;
}

int countCharacters(char *str) {
	int i = 0;
	while(str[i] != '\0') {
		i++;
	}
	return i;
}

bool checkNumbers(char *str) {
	int i = 0;
	int c;
	while(str[i] != '\0') {
		c = str[i];
		if(c >= '0' and c <= '9') {
			return true;
		}
		i++;
	}
	return false;
}

bool checkUpper(char* str) {
	int i = 0;
	while(str[i] != '\0') {
		if(isupper(str[i])) {
			return true;
		}
		i++;
	}
	return false;
}

bool checkLower(char* str) {
	int i = 0;
	while(str[i] != '\0') {
		if(islower(str[i])) {
			return true;
		}
		i++;
	}
	return false;
}

bool checkCase(char* str) {
	return (checkUpper(str) and checkLower(str));
}

void checkPassword(char* str) {
	if (countCharacters(str) < 6) {
		cout << "At least 6 characters.";
	} else if (!checkNumbers(str)) {
		cout << "No numbers.";
	} else if (!checkCase(str)) {
		cout << "No upper or lower case.";
	}
}

int main() {
	// Beklager, har ikke laget all testcode
	// Jeg for skrive den innen jeg møter på sal.


	// Main
	char* str = "J1HN784o";
	getInput(str, 10);
	checkPassword(str);

	//Matrix
	Matrix * m = new Matrix(5);
	cout << m;


	// Jeg har en bug her, men mye av koden skal være kjørbart.
	/**
	while(true) {
		Minesweeper minesweeper;
		minesweeper.play();
		cout << "Again? Y/N";
		char c;
		cin >> c;
		if(toupper(c) != 'Y') break;
	}
	return 0;
	**/
}
