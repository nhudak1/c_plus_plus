/* Nina Hudak
 * Implementation file for complex class: complex_1.cpp
 * April 11, 2019
 */

#include <iostream>
#include <math.h>
#include "complex_1.h"

void Complex::InputC(istream &in)
{
    char i, paren, comma;
    in >> paren >> real >> comma >> imag >> i >> paren;
}

void Complex::OutputC(ostream &out)
{
    out << '(' << real << ',' << imag << "i)" << endl;
}

Complex Complex::AddC(Complex x)
{
    Complex temp;
    temp.real = real + x.real;
    temp.imag = imag + x.imag;
    return temp;
}

Complex Complex::SubC(Complex x)
{
    Complex temp;
    temp.real = real-x.real;
    temp.imag = imag-x.imag;
    return temp;
}

Complex Complex::MultC(Complex x)
{
    Complex temp;
    temp.real = (real*x.real) - (imag*x.imag);
    temp.imag = (imag*x.real) + (real*x.imag);
    return temp;
}

Complex Complex::DivC(Complex x)
{
    Complex temp;
    temp.real = (real*x.real + imag*x.imag) / (real*real + x.imag*x.imag);
    temp.imag = (x.real*imag - real*x.imag) / (x.real*x.real + x.imag*x.imag);
    return temp;
}

Complex Complex::ExpC(int n)
{
    Complex temp, result;
    temp.real = real;
    temp.imag = imag;
    result = temp;

    for(int i=1; i<abs(n); ++i)
        result = result.MultC(temp);
    
    if(n<0)
    {
        if(result.real != 0)
            result.real = 1/result.real;
        if(result.imag != 0)
            result.imag = 1/result.imag;
    }

    return result;
}
