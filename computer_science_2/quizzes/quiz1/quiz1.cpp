/* Nina Hudak
 * Quiz 1: Write a program that efficiently finds the smallest positive
 * integer m which can be expressed as the sum of squares of two
 * positive integers in two different ways. Print all integers in a
 * clearly readable format
 * February 21, 2019
 */

#include <iostream>
#include <iomanip>
#include <climits>
#include <cmath>

using namespace std;

int main()
{   
    int UpperLimit = 20;
    bool found = false;

    for(int a=1; a<UpperLimit && !found; ++a)
    {
        for(int b=a+1; b<UpperLimit && !found; ++b)
        {
            for(int c=a+1; c<UpperLimit && !found; ++c)
            {
                for(int d=c+1; d<UpperLimit && !found; ++d)
                {
                    if(a*a + b*b == c*c + d*d)
                    {
                        cout << "m = " << setw(3) << a*a + b*b << endl;
                        cout << "a = " << setw(3) << a << endl;
                        cout << "b = " << setw(3) << b << endl;
                        cout << "c = " << setw(3) << c << endl;
                        cout << "d = " << setw(3) << d << endl;
                        found = true;
                    }
                }
            }
        }
    }
    
    return 0;
}
