/* Nina Hudak
 * Driver file for polygon class: test-polygon.cpp
 */

#include <iostream>
#include "triangle.h"
#include "polygon.h"

using namespace std;

int main()
{
    double triangle_base, triangle_height;
    Triangle t;

    cout << "\nEnter the base of the triangle: ";
    cin >> triangle_base;
    cout << "Enter the height of the triangle: ";
    cin >> triangle_height;
    t.assign_values(triangle_base, triangle_height);

    cout << "\nArea: " << t.area() << endl;
    t.print_base();
    t.print_height();
    cout << endl;

    return 0;
}
