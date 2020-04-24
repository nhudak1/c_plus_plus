/* Nina Hudak
 * HW 8 Part 1: Design function erase_odd_numbers() that uses find_if()
 * and erase() functions to delete all odd numbers in vector v.
 * March 25, 2019
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

bool odd(int n);

void erase_odd_numbers(vector<int> &v);

int main()
{
    vector<int> v;

    cout << endl;
    initialize(v);
    cout << "Original vector: " << endl;
    print_vector(v.begin(), v.end());
    
    erase_odd_numbers(v);
    cout << "Vector after erasing odd numbers: " << endl;
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
        v.push_back(int(26*random(seed)));
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(4) << *(p++);
    cout << endl;
}

bool odd(int n)
{
    return n%2;
}

void erase_odd_numbers(vector<int> &v)
{
    vector<int>::iterator p = v.begin();
    while(p!=v.end())
    {
        p = find_if(p, v.end(), odd);
        if(p!=v.end())
            p = v.erase(p);
    }
}


