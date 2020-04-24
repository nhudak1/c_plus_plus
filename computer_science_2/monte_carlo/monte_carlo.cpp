/* Nina Hudak
 * Homework 2: Use Monte Carlo method to obtain value of pi
 * February 4, 2019
 */

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

const int TOT_POINTS = 20000;

int main()
{
    double pi, x, y, circle_points = 0;

    for(int i=0; i<TOT_POINTS; ++i)
    {
         x = double(rand())/RAND_MAX;
         y = double(rand())/RAND_MAX;
         if(sqrt((x*x)+(y*y)) <= 1)
             circle_points++;
    }

    pi = (circle_points * 4) / TOT_POINTS;
    cout << "Pi is approximately " << pi << endl;

    return 0;
}
