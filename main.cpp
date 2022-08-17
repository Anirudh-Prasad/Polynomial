// ---------------------------- Main.cpp --------------------------------------
// Anirudh Prasad, CSS 343 A
// Date Created: 01/23/20
// Last Modified: 01/27/20
// ----------------------------------------------------------------------------
// Purpose - This serves as a driver and series of test cases to test the Poly
// class, and its ability to perform the specificied tasks it should do.
// ----------------------------------------------------------------------------
// This driver tests the operators, constructors, and valid/invalid input that
// the program should be able to handle.
// ----------------------------------------------------------------------------

#include "Poly.h";
#include <iostream>;
using namespace std;

int main()
{

	/*cout << "Cin Operator Test" << endl;
	Poly Z;
	cout << "Enter values in order coefficient, exponent. -1 -1 to exit. " << endl;
	cin >> Z;
	cout << "Uno: " << Z << endl;*/

	cout << "\nAssignment-Addition-Subtraction Operator Test, equal term count " << endl;
	Poly A(5, 7);
	A.setCoeff(4, 2);
	Poly B(7, 5);
	B.setCoeff(2, 4);
	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	Poly C = A + B;
	cout << "A + B = C, which is: " << C << endl;
	Poly D = A - B;
	cout << "A - B = D, which is: " << D << endl;

	cout << "\nAssignment-Addition-Subtraction Operator Test, unequal term count " << endl;
	Poly E(5, 7);
	Poly F(3, 7);
	F.setCoeff(9, 4);
	F.setCoeff(12, 2);
	cout << "E: " << E << endl;
	cout << "F: " << F << endl;
	Poly G = E + F;
	cout << "E + F = G, which is: " << G << endl;
	Poly H = E - F;
	cout << "E - F = H, which is: " << H << endl;
	Poly H2 = F - E;
	cout << "F - E = H2, which is: " << H2 << endl;
	
	cout << "\nAssignment Operator Deep Copy Test " << endl;
	Poly I(5, 7);
	Poly J(9, 6);
	cout << "I: " << I << endl;
	cout << "J: " << J << endl;
	J = I;
	I.setCoeff(83, 2);
	J.setCoeff(90, 3);
	cout << "I: " << I << endl;
	cout << "J: " << J << endl;

	cout << "\n+= -= Operator Test " << endl;
	Poly K(2, 4);
	Poly L(15, 4);
	Poly M(14, 4);
	cout << "K: " << K << endl;
	cout << "L: " << L << endl;
	cout << "M: " << M << endl;
	K -= L;
	cout << "K -= L: " << K << endl;
	K += M;
	cout << "K += M: " << K << endl;

	cout << "\nMultiplication Operator Test" << endl;
	Poly N(1, 1);
	N.setCoeff(1, 0);
	cout << "N: " << N << endl;
	Poly O(1, 2);
	O.setCoeff(2, 1);
	O.setCoeff(2, 0);
	cout << "O: " << O << endl;
	cout << "O * N: " << O * N << endl << endl;
	Poly N2(2, 0);
	N2.setCoeff(1, 2);
	cout << "N2: " << N2 << endl;
	Poly O2(2, 0);
	O2.setCoeff(1, 2);
	cout << "O2: " << O2 << endl;
	cout << "O2 * N2: " << O2 * N2 << endl;

	cout << "\n*= Operator Test" << endl;
	Poly P(1, 1);
	P.setCoeff(1, 0);
	Poly Q(1, 2);
	Q.setCoeff(2, 1);
	Q.setCoeff(2, 0);
	Q *= P;
	cout << "Q *= P: " << Q << endl;

	cout << "\nAssignment Operator Deep Copy Test " << endl;
	Poly R(5, 7);
	Poly S(R);
	cout << "R: " << R << endl;
	cout << "S: " << S << endl;
	R.setCoeff(83, 2);
	R.setCoeff(90, 3);
	S.setCoeff(24, 4);
	cout << "R: " << R << endl;
	cout << "S: " << S << endl;

	cout << "\nInvalid Input Testing " << endl;
	Poly T;
	cout << "Default initialization: T = {0}" << endl;
	T.setCoeff(20, -10);
	cout << "T.setCoeff(20, -10): " << T << endl; //should be 0
	T.setCoeff(-10, -1);
	cout << "T.setCoeff(-10, -1): " << T << endl; //should be 0
	cout << "T.getCoeff(1): " << T.getCoeff(1) << endl; //should be 0
	cout << "T.getCoeff(-1): " << T.getCoeff(-1) << endl; //should be 0
	Poly U(7, -1);
	cout << "Poly U(7, -1), output: " << U << endl; //should be +7

}