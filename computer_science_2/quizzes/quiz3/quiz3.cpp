/* Nina Hudak
 * Quiz 3: Sort first half of integers in vector in ascending order,
 * sort second half of vector in descending order
 * April 15, 2019
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <time.h>

const int SIZE = 20;
unsigned long int seed = (unsigned long int)time(0);

using namespace std;

double random(unsigned long int &seed);
void initialize(vector<int> &v);
void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e);
inline bool cmp_int_desc(const int &m, const int &n);

int main()
{
    vector<int> v;
    initialize(v);

    cout << "\nOriginal Vector: " << endl;
    print_vector(v.begin(), v.end());

    sort(v.begin(), v.begin()+SIZE/2);
    sort(v.end()-SIZE/2, v.end(), cmp_int_desc);

    cout << "Sorted Vector: " << endl;
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
        v.push_back(int(1+10*random(seed)));
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(4) << *(p++);
    cout << endl;
}

inline bool cmp_int_desc(const int &m, const int &n)
{
    return m>n;
}
