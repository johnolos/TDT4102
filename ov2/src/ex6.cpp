#include "ex6.h"

// Exercise 6

int add(int num1, int num2) {
	return num1+num2;
}
double add(double num1, double num2) {
	return num1,num2;
}
void add(int &x, int &y, int &z, int &v) {
	v = v + x + y + z;
	z = z + y + x;
	y = y + x;
	return;
}