/* Nina Hudak
 * Lab 8: Create a vector of 20 rand ints between [0,5].
 * Use function find_if() and erase to eliminate all 3's
 * in the vector.
 * March 13, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 20;
unsigned long int seed;

double random(unsigned long int &seed);

void initialize(vector<int> &v);

void print_vector(vector<int>::iterator b,
                  vector<int>::iterator e);

bool is_three(int n);

void erase_3s(vector<int> &v);

int main()
{
    vector<int> v;

    cout << endl;
    initialize(v);
    cout << "Original vector: " << endl;
    print_vector(v.begin(), v.end());

    erase_3s(v);
    cout << "Vector after erasing 3s: " << endl;
    print_vector(v.begin(), v.end());
    cout << endl;

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
        v.push_back(int(6*random(seed)));
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(3) << *(p++);
    cout << endl;
}

bool is_three(int n)
{
    return (n == 3);
}

void erase_3s(vector<int> &v)
{
    vector<int>::iterator p = v.begin();
    while(p!=v.end())
    {
        p = find_if(p, v.end(), is_three);
        if(p!=v.end())
            p = v.erase(p);
    }
}
