#ifndef VECTOR2_H_
#define VECTOR2_H_
#include <iostream>

class Vector2 {
private:
	double numbers[2];
private:

	Vector2() {
		numbers[0] = 0,numbers[1] = 0;
	}
	Vector2(double num1,double num2) {
		numbers[0] = 0,numbers[1] = 0;
	}

	void setNumber(double number, int i) {
		numbers[i] = number;
	}
	double getNumber(int i) const {
		return numbers[i];
	}

	double dot(const Vector2 &other) const;
	double lengthSquared() const;
	double length() const;
	friend ostream& operator <<(ostream& outputStream, const Vector2 &other);

};

#endif
