#pragma once
#include <iostream>
using namespace std;

class Complex {
private:
	double real, imag;

public:

	//  Getters
	double getImag();
	double getReal();

	//  Setters
	void setImag(double _imag = 0);
	void setReal(double _real = 0);

	//  Constructor
	Complex(double _real = 0, double _imag = 0);

	//  Friend functions
	friend ostream& operator<<(ostream& out, const Complex& c);
	friend istream& operator>>(istream& in, Complex& c);

	//  Arithmetic Operators
	Complex operator+(Complex const& c);
	Complex operator-(Complex const& c);
	Complex operator*(Complex const& c);
	Complex operator/(Complex const& c);

	//  Compound assignment operators
	Complex operator=(const Complex& c);
	bool operator==(const Complex& c);
	Complex operator+=(const Complex& c);
	Complex operator-=(const Complex& c);
	Complex operator*=(const Complex& c);
	Complex operator/=(const Complex& c);


};