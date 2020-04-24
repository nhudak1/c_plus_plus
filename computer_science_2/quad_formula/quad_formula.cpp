/* Nina Hudak
 * Program accepts 3 coefficients and outputs real roots of
 * quadratic equation.
 * January 24, 2019
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c, discrim, root1, root2;

    cout << "Please enter 3 coefficients (a, b, c) to find the real roots of\n"
        "the quadratic equation ax^2 + bx + c = 0: ";
    cin >> a >> b >> c;

    if(a==0)
    {
        cout << "\nThis is not a quadratic equation.\n";
        return 0;
    }

    discrim = (b*b) - (4*a*c);
    if(discrim < 0)
    {
        cout << "\nThis equation does not have real roots.\n";
        return 0;
    }

    if((b*b) > (40*a*c))
    {
        root2 = (-b - (b/abs(b)) * sqrt(discrim)) / (2*a);
        root1 = c / (a * root2);
    }
    else
    {
        root1 = (-b + sqrt(discrim)) / (2*a);
        root2 = (-b - sqrt(discrim)) / (2*a);
    }

    cout << "\nRoot 1 = " << root1 << "\tRoot 2 = " << root2 << endl;

    return 0;
}
