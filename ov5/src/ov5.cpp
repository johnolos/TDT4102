#include "Matrix.h"
#include <iostream>


int main() {

	// Test part 2
	/**Part 2(a)
	 * Forfor kan vi ikke bare skrive *this = *this + other?
	 * Vi kan ikke det før vi har implementert operator + som
	 * på dette tidpunktet ikke har gjort.
	 */
	Matrix2x2 A = Matrix2x2(1,2,3,4);
	Matrix2x2 B = Matrix2x2(4,3,2,1);
	Matrix2x2 C = Matrix2x2(1.0,3.0,1.5,2.0);
	Matrix2x2 D1,D2;
	D1 = A+B;
	D2 = D1*B-A+C;
	//D1.printMatrix();
	//D2.printMatrix();
	cout << D1 << D2;
}
