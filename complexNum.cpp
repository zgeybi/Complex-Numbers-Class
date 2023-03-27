#include <iostream>
#include <cmath>
#include "complex.h"
using namespace std;


// Getters

double Complex::getImag()
{
    return imag;
}

double Complex::getReal()
{
    return real;
}

// Setters

void Complex::setImag(double _imag)
{
    imag = _imag;
}

void Complex::setReal(double _real)
{
    real = _real;
}


Complex::Complex(double _real, double _imag)
{
    real = _real;
    imag = _imag;
}
//   Overloaded Input and Output operators

ostream& operator<<(ostream& out, const Complex& c)
{
    out << c.real;

    if (c.imag < 0)
    {
        out << " - i" << (-1) * c.imag << endl;
    }
    else if (c.imag == 0)
    {
        out << endl;
    }
    else
    {
        out << " + i" << c.imag << endl;
    }
    return out;
}

istream& operator>>(istream& in, Complex& c)
{
    cout << "Enter Real Part for the Complex Number: ";
    in >> c.real;
    cout << "Enter Imaginary Part the Complex Number: ";
    in >> c.imag;
    return in;
}

//   Arithmetic operators

Complex Complex::operator+(Complex const& c)
{
    Complex res;
    res.real = real + c.real;
    res.imag = imag + c.imag;
    return res;
}
Complex Complex::operator-(Complex const& c)
{
    Complex res;
    res.real = real - c.real;
    res.imag = imag - c.imag;
    return res;
}
Complex Complex::operator*(Complex const& c)
{
    Complex res;
    res.real = (real * c.real) - (imag * c.imag);
    res.imag = (real * c.imag) + (imag * c.real);
    return res;
}
Complex Complex::operator/(Complex const& c)
{

    Complex res;
    if (c.real != 0 && c.imag != 0) {
        res.real = (real * c.real + imag * c.imag) / (pow(c.real, 2) + pow(c.imag, 2));
        res.imag = (imag * c.real - real * c.imag) / (pow(c.real, 2) + pow(c.imag, 2));
        return res;
    }
    else {
        res.real = 0;
        res.imag = 0;
        cout << "Invalid division, denominator can't be 0, division set to 0" << endl;
        return res;
    }
}


//      Compound assignment operators
Complex Complex::operator=(const Complex& c) 
{
    real = c.real;
    imag = c.imag;

    return *this;
}

bool Complex::operator==(const Complex& c)
{
    if (real == c.real && imag == c.imag)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Complex Complex::operator+=(const Complex& c)
{
    real += c.real;
    imag += c.imag;

    return *this;
}
Complex Complex::operator-=(const Complex& c)
{
    real -= c.real;
    imag -= c.imag;

    return *this;
}
Complex Complex::operator*=(const Complex& c)
{
    double fkreal = real;
    double fkimag = imag;

    real *= c.real;
    real -= (fkimag * c.imag);

    imag *= c.real;
    imag += (fkreal * c.imag);
    return *this;
}
Complex Complex::operator/=(const Complex& c)
{
    double fkreal = real;
    double fkimag = imag;

    real = (fkreal * c.real + fkimag * c.imag);
    real /= (pow(c.real, 2) + pow(c.imag, 2));

    imag = (fkimag * c.real - fkreal * c.imag);
    imag /= (pow(c.real, 2) + pow(c.imag, 2));
    
    return *this;
}



int main()
{

    Complex c1;
    Complex c2;
    
    cout << "Enter two complex numbers in the form of x+iy: " << '\n';
    
    cin >> c1;
    cin >> c2;

    // Using Arithmetic operators
    Complex c3 = c1 + c2;

    Complex c4 = c1 - c2;

    Complex c5 = c1 * c2;

    Complex c6 = c1 / c2;

    cout << "The result of addition is" << endl;
    cout << c3;

    cout << "The result of subtraction is" << endl;
    cout << c4;

    cout << "The result of multiplication is" << endl;
    cout << c5;
    
    cout << "The result of division is" << endl;
    cout << c6;

    // Compound assignment operatrors
    
    cout << "Now enter two other numbers for compound assignment operators: " << endl;
    Complex cc;
    Complex cc2;

    cin >> cc >> cc2;
    Complex copycc = cc;
    

    
    cout << cc << " += " << cc2;
    cc += cc2;
    cout << "The result of addition is" << endl;
    cout << cc;

    cc = copycc;

    
    cout << cc << " -= " << cc2;
    cc -= cc2;
    cout << "The result of subtraction is" << endl;
    cout << cc;

    cc = copycc;

    
    cout << cc << " *= " << cc2;
    cc *= cc2;
    cout << "The result of multiplication is" << endl;
    cout << cc;

    cc = copycc;

    
    cout << cc << " /= " << cc2;
    cc /= cc2;
    cout << "The result of division is" << endl;
    cout << cc;

    return 0;
}
