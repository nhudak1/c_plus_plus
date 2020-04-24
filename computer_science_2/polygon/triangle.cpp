/* Nina Hudak
 * Implementation file for triangle class: triangle.cpp
 */

#include <iostream>
#include "triangle.h"

using namespace std;

double Triangle::area()
{
    return side_a * side_b / 2;
}

double Triangle::return_base()
{
    return side_a;
}

double Triangle::return_height()
{
    return side_b;
}

void Triangle::print_base()
{
    cout << "Base: " << side_a << endl;
}

void Triangle::print_height()
{
    cout << "Height: " << side_b << endl;
}
