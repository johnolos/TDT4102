#include <iostream>
#include <cmath>
#include <cctype>
#include "ex6.h"
using namespace std;

// Exercise 1

double hypotenuse(double side1, double side2) {
	double dob;
	return dob;
}

int sum(int x, int y, int z) {
	return x+y+z;
}

void instructions() {
}

double intToDouble(int integer) {
	return (double)integer;
}

// Exercise 2

void printTime(int hour, int minute, int second) {
	cout << hour << " hours, " << minute << " minutes and " << second << " seconds.";
}

void getTime(int second) {
	int minute = second / 60;
	second -= (minute * 60);
	int hour = minute / 60;
	minute -= (hour * 60);
	cout << hour << " hours, " << minute << " minutes and " << second << " seconds.";
}

// Exercise 3

int randomTenToFifty() {
	return rand() % 41 + 10;
}

float checkTrigonometry(float number) {
	float tannum,sincos;
	tannum = tan(number);
	sincos = sin(number)/cos(number);

	/** Den returnerer 0 dersom man setter inn 1,2,3 osv,
		men for tall som 1.02 og slikt vil deleoperasjonen
		sørge for at man nesten aldri vil 0 pga usikkerhet
		i operasjonen.
	**/

	return tannum-sincos;
}

char changeCase(char i) {
	return (islower(i) ? toupper(i) : tolower(i));
}

// Exercise 4

bool checkLetters(char c, char i) {
	if (!(isalpha(c) && isalpha(i)))
		return false;
	return ((islower(c) && islower(i)) || isupper(c) && isupper(i)) ? true : false;
}


int lengthOfNumber(int number) {
	int i = 0;
	while (number != 0) {
		number = number / 10;
		i++;
	}
	return i;
}

float averageNumber(float num1, float num2) {
	return (num1 + num2) / 2;
}

// Exercise 5
int call_by_value(int A) {
	return (pow(A,2.0) + 10)*2;
}

void call_by_reference(int &A) {
	A = (pow(A,2.0) + 10) * 2;
	return;
}

int main() {
	cout << add(4,5) << endl;
	cout << add(3.5,6.25) << endl;
	int a,b,c,d;
	a = 1;
	b = 2;
	c = 5;
	d = 1;
	add(a,b,c,d);
	cout << a << "\n" << b << "\n" << c << "\n" << d << endl;
	cin >> a;
	return 0;
}
