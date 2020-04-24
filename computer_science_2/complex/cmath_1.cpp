/* Nina Hudak
 * Driver file for complex class: cmath_1.cpp
 * April 11, 2019
 */

#include <iostream>
#include "complex_1.h"

using namespace std;

int main()
{
    char choice;
    Complex a, b, c;
    int exp;

    do
    {
        cout << "\nEnter a complex pair such as (5.1,2.3i): ";
        a.InputC(cin);
        cout << "Enter a complex pair such as (5.1,2.3i): ";
        b.InputC(cin);

        cout << "\nEnter a choice (a)dd, (s)ub, (m)ult, (d)iv, (e)xp: ";
        cin >> choice;

        switch(choice)
        {
            case 'a': 
                c=a.AddC(b);
                break;
            case 's':
                c=a.SubC(b);
                break;
            case 'm':
                c=a.MultC(b);
                break;
            case 'd':
                c=a.DivC(b);
                break;
            case 'e':
                cout << "Enter an integer exponent: ";
                cin >> exp;
                c=a.ExpC(exp);
                break;
            default:
                cout << "Entry Error: ";
        }

        cout << "\nResult is: ";
        c.OutputC(cout);
        cout << endl;

        cout << "Would you like to calculate again? (y)es or (n)o: ";
        cin >> choice;
    }   while(choice == 'y');
    return 0;
}
