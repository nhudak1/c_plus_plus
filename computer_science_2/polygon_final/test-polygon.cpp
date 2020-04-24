//Driver file for class polygon: test-polygon.cpp

#include <iostream>
#include "polygon.h"
#include "trapezoid.h"

using namespace std;

int main()
{
    double side_a, side_b, height;
    Trapezoid t;

    cout << "\nTesting class trapezoid..." << endl;
    cout << "Enter the base one of trapezoid: ";
    cin >> side_a;
    cout << "Enter the base two of trapezoid: ";
    cin >> side_b;
    t.assign_values(side_a, side_b);

    cout << "Enter the height of trapezoid: ";
    cin >> height;
    t.assign_trapez_height(height);


    cout << "Area of trapezoid is: " << t.area() << endl;
    cout << endl;

    return 0;
}
