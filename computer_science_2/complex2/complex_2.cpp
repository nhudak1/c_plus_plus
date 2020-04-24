/* Nina Hudak
 * Implementation file for complex class: complex_2.cpp
 * April 11, 2019
 */

#include <iostream>
#include <math.h>
#include "complex_2.h"

Complex::Complex(double init_real, double init_imag)
{
    real = init_real;
    imag = init_imag;
}

void Complex::InputC(istream &in)
{
    char i, paren, comma;
    in >> paren >> real >> comma >> imag >> i >> paren;
}

void Complex::OutputC(ostream &out)
{
    out << '(' << real << ',' << imag << "i)" << endl;
}

Complex Complex::operator + (Complex x)
{
    Complex temp;
    temp.real = real + x.real;
    temp.imag = imag + x.imag;
    return temp;
}

Complex Complex::operator - (Complex x)
{
    Complex temp;
    temp.real = real-x.real;
    temp.imag = imag-x.imag;
    return temp;
}

Complex Complex::operator * (Complex x)
{
    Complex temp;
    temp.real = (real*x.real) - (imag*x.imag);
    temp.imag = (imag*x.real) + (real*x.imag);
    return temp;
}

Complex Complex::operator / (Complex x)
{
    Complex temp;
    temp.real = (real*x.real + imag*x.imag) / (real*real + x.imag*x.imag);
    temp.imag = (x.real*imag - real*x.imag) / (x.real*x.real + x.imag*x.imag);
    return temp;
}

Complex Complex::operator ^ (int n)
{
    Complex temp, result;
    temp.real = real;
    temp.imag = imag;
    result = temp;

    for(int i=1; i<abs(n); ++i)
        result = result * temp;
    
    if(n<0)
    {
        if(result.real != 0)
            result.real = 1/result.real;
        if(result.imag != 0)
            result.imag = 1/result.imag;
    }

    return result;
}

ostream &operator << (ostream &out, Complex x)
{
    x.OutputC(out);
    return (out);
}

istream &operator >> (istream &in, Complex &x)
{
    x.InputC(in);
    return (in);
}
