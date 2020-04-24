/* Nina Hudak
 * Lab 3: Man travelling in rowboat. Generate random lengths
 * that will give a shorter travel time each iteration.
 * February 6, 2019
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE=10000, LENGTH=15, AB=8, EH=6, BC=3, DH=4, CD=5;

double random(unsigned long int &seed);

int main()
{
    unsigned long int seed;
    double f1, f2, f3, x, y, z, t=100, new_time;
    cout << setprecision(5) << fixed << showpoint;

    for(int i=0; i<SIZE; ++i)
    {
        f1 = random(seed);
        f2 = random(seed);
        f3 = random(seed);

        x = LENGTH * f1/(f1+f2+f3);
        y = LENGTH * f2/(f1+f2+f3);
        z = LENGTH * f3/(f1+f2+f3);

        new_time = sqrt(AB*AB + x*x)/BC + y/CD + sqrt(EH*EH + z*z)/DH;

        if(new_time<t)
        {
            t = new_time;
            cout << "x = " << setw(10) << x << endl;
            cout << "y = " << setw(10) << y << endl;
            cout << "z = " << setw(10) << z << endl;
            cout << "t = " << setw(10) << t << "\n\n";
        }
    }
    return 0;
}

double random(unsigned long int &seed)
{
    const int MODULUS=15749;
    const int MULTIPLIER=69069;
    const int INCREMENT=1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return double(seed)/MODULUS;
}
