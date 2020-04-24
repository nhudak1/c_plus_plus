/* Nina Hudak
 * Quiz 2: Initialize an integer vector v of size SIZE
 * with distinct random integers, each in range [0, 2*SIZE].
 * March 28, 2019
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

int main()
{
    vector<int> v;

    initialize(v);
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
    int temp;
    bool found;

    for(int i=0; i<SIZE; ++i)
    {
        do
        {
            temp = int((2*SIZE+1)*random(seed));
            found = false;

            for(vector<int>::iterator p=v.begin(); p<v.end() && found==false; ++p)
            {
                if(*p == temp)
                    found = true;
            }
        }while(found == true);

        v.push_back(temp);
    }
        
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    vector<int>::iterator p = b;
    while(p<e)
        cout << setw(4) << *(p++);
    cout << endl;
}
