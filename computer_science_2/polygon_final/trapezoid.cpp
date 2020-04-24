//Implementation file for class Trapezoid: trapezoid.cpp

#include <iostream>
#include "polygon.h"
#include "trapezoid.h"

using namespace std;

void Trapezoid::assign_trapez_height(double h)
{
    height = h;
}

double Trapezoid::area()
{
    return (side_a + side_b) * (height/2);
}
