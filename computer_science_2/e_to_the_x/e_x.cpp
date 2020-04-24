#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, term = 1.0, old_sum=0.0, new_sum=term;
    int i=0;

    cin >> x;
    
    while(old_sum!=new_sum)
    {
        old_sum=new_sum;
        term = term*x/(i+1);
        new_sum += term;
        i++;
    }

    cout << new_sum << endl;
    cout << exp(x) << endl;

    return 0;

}
