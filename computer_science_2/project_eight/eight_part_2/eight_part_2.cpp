/* Nina Hudak
 * HW 8 Part 2: Design function insert_before_odd(v) that uses
 * find_if() to find odd numbers in vector v and function insert()
 * to insert -1 in front of every odd number.
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

void insert_before_odd(vector<int> &v);

int main()
{
    vector<int> v;

    cout << endl;
    initialize(v);
    cout << "Original Vector: " << endl;
    print_vector(v.begin(), v.end());

    insert_before_odd(v);
    cout << "Vector after inserting -1 before all odd numbers: " << endl;
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
        v.push_back(int(10*random(seed)));
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(3) << *(p++);
    cout << endl;
}

bool odd(int n)
{
    return n%2;
}

void insert_before_odd(vector<int> &v)
{
    vector<int>::iterator p = v.begin();
    while(p!=v.end())
    {
        p = find_if(p, v.end(), odd);
        if(p!=v.end())
        {
            p = v.insert(p, -1);
            p+=2;
        }
    }
}
