#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
using namespace std;

class Matrix {
private:
	int row, col;
	double * matrix;
public:
	Matrix();
	explicit Matrix(unsigned int rows);
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(const Matrix &other);
	Matrix& operator=(const Matrix &other);
	~Matrix();
	double get(unsigned int row,unsigned int col);
	void set(unsigned int row,unsigned int col, double dob);
	bool isValid();
	Matrix& operator+=(const Matrix &other);
	Matrix& operator-=(const Matrix &other);
	Matrix& operator+(const Matrix &other);
	Matrix& operator-(const Matrix &other);
	Matrix operator*(const Matrix &other);
	Matrix& operator*=(const Matrix &other);
	friend ostream& operator <<(ostream &out, Matrix &m);

};



#endif
