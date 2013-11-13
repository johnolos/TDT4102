#include "math.h"
#include "iostream.h"
#include "Vector2.h"

double Vector2::dot(const Vector2 &other) const{
	return (this->getNumber(0)*other.getNumber(0) + this->getNumber(1)*other.getNumber(1));
}
double Vector2::lengthSquared() const {
	return sqrt(this->length());
}
double Vector2::length() const {
	return sqrt(pow(this->getNumber(0),2.0) + pow(this->getNumber(1),2.0));
}

ostream& operator <<(ostream& out, const Vector2 &other) {
		out << "[" << other.numbers[0] << "," << other.numbers[1] << "]";
		return out;
	}

