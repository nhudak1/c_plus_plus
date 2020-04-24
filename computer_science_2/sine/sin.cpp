/* Nina Hudak
 * Homework 3: Compute sin(x)
 * February 11, 2019
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, term, old_sum = 0.0, new_sum;
    int i = 1;

    cout << setprecision(5) << fixed << showpoint;

    do
    {
        cout << "Please enter a value between -pi/2 and pi/2: ";
        cin >> x;
    }while(x<-1*M_PI_2 || x>M_PI_2);

    term = x;
    new_sum = term;

    while(old_sum != new_sum)
    {
        old_sum = new_sum;
        term = term*x*x*(-1)/(i*i + 3*i + 2);
        new_sum += term;
        i += 2;
    }
    
    cout << "Calculation:\t\t sin(" << x << ") = ";
    cout << setw(10) << new_sum << endl;
    cout << "Built-in Function:\t sin(" << x << ") = ";
    cout << setw(10) << sin(x) << endl;

    return 0;
}
