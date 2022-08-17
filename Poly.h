// ---------------------------- Poly.h ----------------------------------------
// Anirudh Prasad, CSS 343 A
// Date Created: 01/20/20
// Last Modified: 01/27/20
// ----------------------------------------------------------------------------
// Purpose - This serves as a header file for an implementation of a program
// that creates polynomials and handles various calculations, such as addition,
// subtraction, multiplication, assignment, and various boolean tests between
// multiple polynomials.
// ----------------------------------------------------------------------------
// This program dynamically allocates arrays while not having any memory leaks
// occur. 
// ----------------------------------------------------------------------------

#pragma once
#include <iostream> //for input/output
using namespace std;

class Poly
{
	//<< operator overload
	friend ostream& operator << (ostream& output, const Poly poly);
	//>> operator overload
	friend istream& operator >> (istream& input, Poly& poly);
public:
	//default constructor
	 Poly();
	 //destructor deletes polyarr and frees memory
	 ~Poly();
	 //constructor takes two ints and initializes coeff at polyArr[loc]
	 Poly(int co, int pow);
	 //single int constructor, assigns coefficient at location 0
	 Poly(int co);
	 //copy constructor
	 Poly(const Poly& A);
	 //returns coefficient at location loc
	 int getCoeff(int loc) const;
	 //sets coefficient coeff at location loc
	 void setCoeff(int coeff, int loc);
	 //returns size of polynomial
	 int getSize() const;
	 //+ operator overload
	 Poly operator + (const Poly& p1);
	 //- operator overload
	 Poly operator - (const Poly& p1);
	 //*operator overload
	 Poly operator * (const Poly& p1);
	 //= operator overload
	 Poly operator = (const Poly& p1);
	 //+= operator overload
	 Poly operator += (const Poly& p1);
	 //-= operator overload
	 Poly operator -= (const Poly& p1);
	 //*= operator overload
	 Poly operator *= (const Poly& p1);
	 //== operator overload
	 bool operator == (const Poly& p1);
	 //!=  operator overload
	 bool operator != (const Poly& p1);


private:
	//array that holds polynomial coefficients
	int* polyArr;
	//int that contains size of polynomial, where size = lastIdx + 1
	int size;
	//Updates polynomial to size int lim, adjusts polyArr
	void updatePoly(int lim);
};


