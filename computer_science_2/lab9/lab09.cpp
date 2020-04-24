/* Nina Hudak
 * Lab 9: Wite program that creates a vector of 10 random
 * integers in range [0, 10]. Replace each occurence of 5
 * with 0. You must use function find_if(). 
 * March 27, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 10;
unsigned long int seed;

double random(unsigned long int &seed);

void initialize(vector<int> &v);

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e);

bool is_five(int n);

void replace_five(vector<int> &v);

int main()
{
    vector<int> v;
    initialize(v);

    cout << "\nVector before replacement:" << endl;
    print_vector(v.begin(), v.end());

    replace_five(v);
    cout << "Vector after replacement:" << endl;
    print_vector(v.begin(), v.end());

    return 0;
}

double random(unsigned long int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return double(seed)/MODULUS;
}

void initialize(vector<int> &v)
{
    for(int i=0; i<SIZE; ++i)
        v.push_back(int(11*random(seed)));
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(3) << *(p++);
    cout << endl;
}

bool is_five(int n)
{
    return (n==5);
}

void replace_five(vector<int> &v)
{
    vector<int>::iterator p = v.begin();
    while(p!=v.end())
    {
        p = find_if(p, v.end(), is_five);
        if(p!=v.end())
            *p = 0;
    }
}
