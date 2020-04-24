/* Nina Hudak
 * Driver file for complex class: cmath_2.cpp
 * April 11, 2019
 */

#include <iostream>
#include "complex_2.h"

using namespace std;

int main()
{
    char choice;
    Complex a, b, c;
    int exp;

    do
    {
        cout << "\nEnter a complex pair such as (5.1,2.3i): ";
        cin >> a;
        cout << "Enter a complex pair such as (5.1,2.3i): ";
        cin >> b;

        cout << "\nEnter a choice (a)dd, (s)ub, (m)ult, (d)iv, (e)xp: ";
        cin >> choice;

        switch(choice)
        {
            case 'a': 
                c= a + b;
                break;
            case 's':
                c= a - b;
                break;
            case 'm':
                c= a * b;
                break;
            case 'd':
                c= a / b;
                break;
            case 'e':
                cout << "Enter an integer exponent: ";
                cin >> exp;
                c= a ^ exp;
                break;
            default:
                cout << "Entry Error: ";
        }

        cout << "\nResult is: " << c << endl;
       
        cout << "Would you like to calculate again? (y)es or (n)o: ";
        cin >> choice;
    }   while(choice == 'y');
    return 0;
}

