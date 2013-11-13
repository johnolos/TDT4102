#include "Matrix.h"
#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))

// Construction
Matrix2x2::Matrix2x2() {
	setNumber(0,0,1);
	setNumber(0,1,0);
	setNumber(1,0,0);
	setNumber(1,1,1);
}

Matrix2x2::Matrix2x2(double num1, double num2, double num3, double num4) {
	setNumber(0,0,num1);
	setNumber(0,1,num2);
	setNumber(1,0,num3);
	setNumber(1,1,num4);
}

// Functions
void Matrix2x2::setNumber(int row, int col, double number) {
	this->numbers[row][col] = number;
}

double Matrix2x2::getNumber(int row, int col) {
	return this->numbers[row][col];
}

Matrix2x2 Matrix2x2::operator*=(Matrix2x2 &other) {
	*this = *this * other;
	return *this;
}

double Matrix2x2::det() {
	return this->getNumber(0,0)*this->getNumber(1,1)-this->getNumber(0,1)*this->getNumber(1,0);
}

Matrix2x2 Matrix2x2::operator +(Matrix2x2 &other) {
		return Matrix2x2(this->getNumber(0,0)+other.getNumber(0,0), this->getNumber(0,1)+other.getNumber(0,1),
				this->getNumber(1,0)+other.getNumber(1,0),this->getNumber(1,1)+other.getNumber(1,1));
	}

Matrix2x2 Matrix2x2::operator -(Matrix2x2 &other) {
	return Matrix2x2(this->getNumber(0,0)-other.getNumber(0,0), this->getNumber(0,1)-other.getNumber(0,1),
					this->getNumber(1,0)-other.getNumber(1,0),this->getNumber(1,1)-other.getNumber(1,1));
}

Matrix2x2 Matrix2x2::operator-=(Matrix2x2 &other) {
	*this = *this - other;
	return *this;
}

Matrix2x2 Matrix2x2::operator+=(Matrix2x2 &other) {
	*this = *this + other;
	return *this;
}

Matrix2x2 Matrix2x2::operator *(Matrix2x2 &other) {
	double numbers[2][2];
	numbers[0][0] = this->getNumber(0,0)*other.getNumber(0,0)+this->getNumber(0,1)*other.getNumber(1,0);
	numbers[0][1] = this->getNumber(0,0)*other.getNumber(0,1)+this->getNumber(0,1)*other.getNumber(1,1);
	numbers[1][0] = this->getNumber(1,0)*other.getNumber(0,0)+this->getNumber(1,1)*other.getNumber(0,1);
	numbers[1][1] = this->getNumber(1,0)*other.getNumber(0,1)+this->getNumber(1,1)*other.getNumber(1,1);
	return Matrix2x2(numbers[0][0],numbers[0][1],numbers[1][0],numbers[1][1]);
}
ostream& operator << (ostream &out, Matrix2x2 &mx) {
	out << "[";
	for(unsigned int i = 0; i < ARRAY_SIZE(mx.numbers); i++) {
		out << "[";
		for(unsigned int j = 0; j < ARRAY_SIZE(mx.numbers[0]); j++) {
			if(j == ARRAY_SIZE(mx.numbers[0])-1) {
				out << mx.numbers[i][j];
				break;
			}
			out << mx.numbers[i][j] << "\t";
		}
		if(i == ARRAY_SIZE(mx.numbers)-1){
			out << "]";
			break;
		}
		out << "]" << endl;
	}
	out << "]" << endl;
	return out;
}

Matrix2x2 Matrix2x2::inverse() {
	double determinant = this->det();
	if(determinant == 0.0) {
		return Matrix2x2(0.0,0.0,0.0,0.0);
	}
	determinant = 1 / determinant;
	Matrix2x2 result = Matrix2x2(determinant*this->numbers[1][1],determinant*-this->numbers[0][1],
			determinant*-this->numbers[1][0],determinant*this->numbers[0][0]);
	return result;
}
