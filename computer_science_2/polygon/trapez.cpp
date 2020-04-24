/* Nina Hudak
 * Trapez class implementation file: trapez.cpp
 */

#include "trapez.h"

double Trapez::area()
{
    return (side_a + side_b) * height / 2;
}

void Trapez::assign_trapez_height(double h)
{
    height = h;
}
