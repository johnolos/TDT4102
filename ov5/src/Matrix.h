#ifndef MATRIX_H_
#define MATRIX_H_
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))
#include "iostream.h"
#include <iostream>

class Matrix2x2 {
private:
	double numbers[2][2];

public:
	Matrix2x2();
	Matrix2x2(double num1, double num2, double num3, double num4);
	void setNumber(int row, int col, double number);
	double getNumber(int row, int col);

	void printMatrix() {
		cout << "[";
		for(unsigned int i = 0; i < ARRAY_SIZE(numbers); i++) {
			cout << "[";
			for(unsigned int j = 0; j < ARRAY_SIZE(numbers[0]); j++) {
				if(j == ARRAY_SIZE(numbers[0])-1) {
					cout << numbers[i][j];
					break;
				}
				cout << numbers[i][j] << "\t";
			}
			if(i == ARRAY_SIZE(numbers)-1){
				cout << "]" << endl;
				break;
			}
			cout << "]" << endl;
		}
		cout << "]";
	}

	Matrix2x2 operator +(Matrix2x2 &other);
	Matrix2x2 operator -(Matrix2x2 &other);
	Matrix2x2 operator *(Matrix2x2 &other);
	Matrix2x2 operator+=(Matrix2x2 &other);
	Matrix2x2 operator-=(Matrix2x2 &other);
	Matrix2x2 operator*=(Matrix2x2 &other);
	friend ostream& operator << (ostream &out, Matrix2x2 &mx);
	double det();
	Matrix2x2 inverse();
};
#endif
