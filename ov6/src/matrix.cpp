#include "Matrix.h"

Matrix::Matrix(): matrix(NULL), row(0), col(0) {}

Matrix::Matrix(unsigned int row, unsigned int col) {
	this->matrix = new double* [row];
	for(unsigned int i = 0; i < row; i++) {
		matrix[i] = new double [col];
		for(unsigned int j = 0; j < col; j++) {
			matrix[i][j] = 0.0;
		}
	}
	this->row = row, this->col = col;
}

Matrix::Matrix(unsigned int rows) {
	this->matrix = new double* [rows];
	for(int i = 0; i < rows; i++) {
		matrix[i] = new double [rows];

		for(int j = 0; j < rows; j++) {
			if(i == j)
				matrix[i][j] = 1.0;
			else
				matrix[i][j] = 0.0;
		}
	}
	this->row = rows, this->col = rows;
}

Matrix::Matrix(const Matrix &other): matrix(NULL), row(other.row), col(other.col) {
	this->matrix = new double * [row];
	for(unsigned int i = 0; i < row; i++) {
		matrix[i] = new double[col];
		for(unsigned int j = 0; j < col; j++)
			matrix[i][j] = other.matrix[i][j];
	}
}


bool Matrix::isValid() {
	return (matrix != NULL || (this->row == 0 && this->col == 0));
}



Matrix::~Matrix() {
	for(int i = 0; i < row; i++) {
		delete [] matrix[i];
	}
	delete [] matrix;
}


double Matrix::get(unsigned int row,unsigned int col) {
	return this->matrix[row][col];
}
void Matrix::set(unsigned int row,unsigned int col, double dob) {
	this->matrix[row][col] = dob;
}

Matrix& Matrix::operator=(const Matrix &other) {
	if(this->isValid()) {
		this->~Matrix();
	}
	this->row = other.row;
	this->col = other.col;
	this->matrix = new double * [row];
	for(unsigned int i = 0; i < row; i++){
		matrix[i] = new double[col];
		for(unsigned int j = 0; j < col; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
	return *this;
}

Matrix& Matrix::operator +=(const Matrix &other) {
	if(this->row == other.row && this->col == other.col) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				matrix[i][j] += other.matrix[i][j];
			}
		}
		return *this;
	}
	return Matrix();
}

Matrix& Matrix::operator -=(const Matrix &other) {
	if(this->isValid() && this->row == other.row && this->col == other.col) {
		for(int i = 0; i < row; i++) {
			for(int j = 0; j < col; j++) {
				matrix[i][j] -= other.matrix[i][j];
			}
		}
		return *this;
	}
	return Matrix();
}

Matrix& Matrix::operator+(const Matrix &other) {
	*this += other;
	return *this;
}

Matrix& Matrix::operator-(const Matrix &other) {
	*this -= other;
	return *this;
}

Matrix Matrix::operator *(const Matrix &other) {
	if(this->row == other.col && this->isValid()) {
		Matrix returnMatrix = Matrix(this->row,other.col);
		for(int i = 0; i < this->row; i++) {
			for(int j = 0; j < other.col; j++) {
				for(int k = 0; k < this->col; k++) {
					returnMatrix.matrix[i][k] * other.matrix[k][j];
				}
			}
		}
		return returnMatrix;
	} else {
		return Matrix();
	}
}

Matrix& Matrix::operator *=(const Matrix &other) {
	*this = *this * other;
	return *this;
}

ostream& operator <<(ostream &out, Matrix &m) {
	if(m.isValid()) {
		for(unsigned int i = 0; i < m.row; i++) {
			for(unsigned int j = 0; j < m.col; j++) {
				out << m.matrix[i][j] << "\t";
			}
			out << endl;
		}
		return out;
	}
	return out << "Invalid matrix";
}
