/* Nina Hudak
 * Extra Credit 3: Write a program that uses an integer vector
 * to store DIST_INT number of random distinct integers and uses
 * function print_pairs(v) that outputs the pairs of integers contained
 * in the vector that add up to the specified value of SUM.
 * April 25, 2019
 */

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>

const int SIZE = 15;
const int DIST_INT = 5;
const int SUM = 9;
unsigned long int seed = (unsigned long int)time(0);

using namespace std;

struct Pair
{
    int m, n;
};

double random(unsigned long int &seed);
bool new_integer(const vector<int> &v, int new_integer);
void initialize(vector<int> &v);
void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e);
void print_pairs(vector<int> &v);

int main()
{
    vector<int> v;
    initialize(v);
    cout << "\nVector:" << endl;
    print_vector(v.begin(), v.end());
    cout << "Pairs:" << endl;
    print_pairs(v);
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

bool new_integer(const vector<int> &v, int new_integer)
{
    bool not_found = true;
    int i = 0;

    while(not_found && i<v.size())
    {
        if(v[i] == new_integer)
            not_found = false;
        ++i;
    }

    return not_found;
}

void initialize(vector<int> &v)
{
    int i=0, temp_integer;
    while(i<DIST_INT)
    {
        temp_integer = int(1+9*random(seed));
        if(new_integer(v, temp_integer))
        {
            v.push_back(temp_integer);
            ++i;
        }
    }
    for(int i=0; i<SIZE-DIST_INT; ++i)
        v.push_back(0);
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(3) << *(p++);
    cout << endl;
}

void print_pairs(vector<int> &v)
{
    vector<int>::iterator p = v.begin();
    vector<int>::iterator q = v.begin() + 1;
    int pairs_found = 0;

    //Works whether or not there are extra zeros at end of vector
    do
    {
        if(*q == 0 || q == v.end())
        {
            p++;
            q = p+1;
        }
        else if(*p == SUM - *q && *q != 0)
        {
            cout << setw(2) << *p << " --";
            cout << setw(2) << *q << endl;
            p++;
            q = p+1;
            pairs_found++;
        }
        else
            q++;
    }   while(*p != 0 && p != v.end()-1);

    if(pairs_found == 0)
        cout << " No pairs found" << endl;
    cout << endl;
}
