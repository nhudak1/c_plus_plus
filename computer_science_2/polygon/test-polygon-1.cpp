/* Nina Hudak
 * Driver file for polygon class: test-polygon.cpp
 */

#include <iostream>
#include <iomanip>

#include "trapez.h"
#include "triangle.h"

using namespace std;

int main()
{
    double triangle_base, triangle_height;
    double trapez_bottom_base, trapez_upper_base, trapez_height;
    Triangle t_1;
    Trapez t_2;

    cout << "\nTesting class triangle..." << endl;
    cout << "Enter the base of the triangle: ";
    cin >> triangle_base;
    cout << "Enter the height of the triangle: ";
    cin >> triangle_height;
    t_1.assign_values(triangle_base, triangle_height);
    cout << "\nArea of t_1 is: " << t_1.area() << endl;
    
    cout << "\nTesting class trapez..." << endl;
    cout << "Enter bottom base of trapez: ";
    cin >> trapez_bottom_base;
    cout << "Enter upper base of trapez: ";
    cin >> trapez_upper_base;
    t_2.assign_values(trapez_bottom_base, trapez_upper_base);
    cout << "Enter the height of trapez: ";
    cin >> trapez_height;
    t_2.assign_trapez_height(trapez_height);
    cout << "Area of trapez t_2 is: ";
    cout << t_2.area() << endl;
    cout << endl;

    return 0;
}
