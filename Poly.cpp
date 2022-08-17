// ---------------------------- Poly.cpp --------------------------------------
// Anirudh Prasad, CSS 343 A
// Date Created: 01/20/20
// Last Modified: 01/27/20
// ----------------------------------------------------------------------------
// Purpose - This serves as an implementation file for an implementation of a 
// program that creates polynomials and handles various calculations, such as 
// addition, subtraction, multiplication, assignment, and various boolean tests 
// between multiple polynomials.
// ----------------------------------------------------------------------------
// This program resizes the polynomial by dynamically allocates arrays while 
// not having any memory leaks occur. 
// ----------------------------------------------------------------------------

#include "Poly.h"

//Default constructor
Poly::Poly()
{
	size = 1;
	polyArr = new int[size] {0};
	polyArr[size - 1] = 0;
}

//Destructor
Poly::~Poly()
{
	delete[] polyArr;
}

//Contructor that takes in an int coefficient and an int location
//Creates polynomial with size of pow + 1
Poly::Poly(int co, int pow)
{
	if (pow < 0) 
	{
		size = 1;
		polyArr = new int[size] {0};
		polyArr[size - 1] = co;
	}
	else 
	{
		size = pow + 1;
		polyArr = new int[size] {0};
		polyArr[pow] = co;
	}
}

//Constructor that takes in an int coefficient
//Initializes first element in array to co
Poly::Poly(int co)
{
	size = 1;
	polyArr = new int[size];
	polyArr[0] = co;
}

//Copy contructor that provides a deep copy of Poly in Parameter.
Poly::Poly(const Poly& A)
{
	size = A.size;
	polyArr = new int[size] {0};
	for (int i = 0; i < size; i++) {
		polyArr[i] = A.polyArr[i];
	}

}

//returns coefficient stored in param location
int Poly::getCoeff(int loc) const
{
	if (loc < 0) return 0;
	if (loc >= size) return 0;

	return polyArr[loc];
}

//sets coefficient based on location via int parameters
void Poly::setCoeff(int coeff, int loc)
{
	if (loc < 0) return;
	if (loc >= size) {
		updatePoly(loc + 1);
	}

	polyArr[loc] = coeff;
}

//returns size of polynomial
int Poly::getSize() const
{
	return size;
}

//private method that updates size of polynomial
//dynamically allocates new array with specified size
void Poly::updatePoly(int lim)
{
	int* newArr = new int[lim] {};

	for (int i = 0; i < size; i++)
	{
		newArr[i] = polyArr[i];
	}

	size = lim;
	delete[] polyArr; //deletes old arr to free memory
	polyArr = newArr;
}

//Adds two polynomial objects together
//Accounts for different sizes
Poly Poly::operator + (const Poly& p1)
{
	Poly ret;
	int lim = size;
	if (size > p1.size) lim = p1.size; //choose ret size based on smaller poly

	ret.size = lim;
	ret.updatePoly(size);
	for (int i = 0; i < ret.size; i++) { //add all terms from smaller poly
		ret.polyArr[i] = this->polyArr[i] + p1.polyArr[i];
	}

	//determines whether or not to add remaining terms based on size difference
	if (p1.size != size)
	{
		if (size < p1.size)
		{
			ret.updatePoly(p1.size);
			for (int i = size; i < p1.size; i++) {
				ret.polyArr[i] = p1.polyArr[i];
			}
		}
		else
		{ //if this->size > p1.size
			ret.updatePoly(size);
			for (int i = p1.size; i < size; i++)
			{
				ret.polyArr[i] = polyArr[i];
			}
		}
	}

	return ret;
}

//Subtracts one polynomial from another
//Accounts for different sizes
Poly Poly::operator - (const Poly& p1)
{
	Poly ret;
	int lim = size;
	if (size > p1.size) lim = p1.size; //choose ret size based on smaller poly

	ret.size = lim;
	ret.updatePoly(size);
	for (int i = 0; i < ret.size; i++)
	{ //subtract all terms based on size from smaller poly
		ret.polyArr[i] = this->polyArr[i] - p1.polyArr[i];
	}

	//determines whether or not to add remaining terms based on size difference
	if (p1.size != size)
	{
		if (size < p1.size)
		{
			ret.updatePoly(p1.size);
			for (int i = size; i < p1.size; i++)
			{
				ret.polyArr[i] = 0 - p1.polyArr[i];
			}
		}
		else
		{ //if this->size > p1.size
			ret.updatePoly(size);
			for (int i = p1.size; i < size; i++)
			{
				ret.polyArr[i] = polyArr[i];
			}
		}
	}

	return ret;
}

//Multiplies two polynomials together
//Dynamically allocates 2D array and deletes it
Poly Poly::operator * (const Poly& p1)
{
	Poly ret;
	int lim = size + p1.size;
	ret.updatePoly(lim);

	int** arr = new int* [size] {};
	for (int i = 0; i < size; i++)
	{
		arr[i] = new int[lim] {};
	}

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < p1.size; c++)
		{
			arr[r][r + c] += polyArr[r] * p1.polyArr[c];
		}
	}

	for (int c = 0; c < lim; c++)
	{
		for (int r = 0; r < size; r++)
		{
			ret.polyArr[c] += arr[r][c];
		}
	}

	for (int i = 0; i < size; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	return ret;
}

//Assignment operator overload to set one Poly object equal to another
Poly Poly::operator = (const Poly& p1)
{
	updatePoly(p1.size);
	for (int i = 0; i < size; i++)
	{
		polyArr[i] = p1.polyArr[i];
	}
	return *this;
}

//Overloaded operator to set one Poly equal to sum of both objects
Poly Poly::operator += (const Poly& p1)
{
	if (size < p1.size) updatePoly(p1.size);

	for (int i = 0; i < size; i++)
	{
		polyArr[i] += p1.polyArr[i];
	}

	return *this;
}

//Overloaded operator to set one Poly equal to difference of both objects
Poly Poly::operator -= (const Poly& p1)
{
	if (size < p1.size) updatePoly(p1.size);

	for (int i = 0; i < size; i++)
	{
		polyArr[i] -= p1.polyArr[i];
	}

	return *this;
}

//Overloaded operator to set one Poly equal to product of both objects
Poly Poly::operator *= (const Poly& p1)
{
	*this = (*this) * p1;
	return *this;
}

//boolean equality operator overload to test if two Poly objects are equal
bool Poly::operator == (const Poly& p1)
{
	if (size != p1.size) return false;
	for (int i = 0; i < size; i++)
	{
		if (polyArr[i] != p1.polyArr[i]) return false;
	}
	return true;
}

//boolean inequality operator overload, tests if two Poly objects aren't equal
bool Poly::operator != (const Poly& p1)
{
	if (size != p1.size) return true;
	for (int i = 0; i < size; i++)
	{
		if (polyArr[i] != p1.polyArr[i]) return true;
	}
	return false;
}

//Insertion operator overload to output Polynomial data in correct format
ostream& operator << (ostream& output, const Poly poly)
{
	bool test = false;
	for (int i = 0; i < poly.size; i++)
	{
		if (poly.polyArr[i] != 0) test = true;
	}
	if (test == false)
	{
		output << "0";
		return output;
	}

	for (int i = poly.size - 1; i >= 0; i--)
	{
		int coeff = poly.polyArr[i];
		if (coeff > 0)
		{
			output << " +";
		}
		else if (coeff < 0)
		{
			coeff = 0 - coeff;
			output << " -";
		}
		else continue; //break if coeffiecient = 0

		if (i == 0)
		{
			output << coeff;
		}
		else if (i == 1)
		{
			output << coeff << "x";
		}
		else
		{
			output << coeff << "x" << "^" << i;
		}
	}

	return output;
}

//Extraction Operator overload for user and file input
istream& operator >> (istream& input, Poly& poly)
{
	int co;
	int loc;
	while (true)
	{
		input >> co >> loc;
		if (co == -1 && loc == -1)
		{
			break;
		}
		poly.setCoeff(co, loc);
	}
	cout << poly;
	return input;
}
