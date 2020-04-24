/* Nina Hudak
 * Lab 6: Create a vector of 12 random integers and print out odd numbers.
 * Make sure everything is aligned.
 * February 27, 2016
 *
 * "Original vector:"
 * "Odd numbers in the vector:"
 */

#include <iostream>
#include <iomanip>
#include <ctime>
#include <vector>

using namespace std;

const int SIZE = 12;
unsigned int seed = (unsigned int)time(0);

double random(unsigned int &seed);
bool odd(int n);
void initialize_array(int a[]);
void initialize_vector(int a[], vector<int> &v);
void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e);
void print_vector_odd(const vector<int> &v);
void print_vector_even(const vector<int> &v);

int main()
{
    int a[SIZE];
    vector<int> v;
    //cout << v.size() << endl;
    cout << endl;
    initialize_array(a);
    initialize_vector(a, v);
    //cout << v.size() << endl;
    print_vector(v.begin(), v.end());
    print_vector_odd(v);
    print_vector_even(v);
    cout << endl;

    return 0;
}

double random(unsigned int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return float(seed)/float(MODULUS);
}

bool odd(int n)
{
    return n%2;
}

void initialize_array(int a[])
{
    for(int i=0; i<SIZE; ++i)
        a[i] = int(10*random(seed));
    return;
}

void initialize_vector(int a[], vector<int> &v)
{
    for(int i=0; i<SIZE; ++i)
        v.push_back(a[i]);
    return;
}

void print_vector(vector<int>::iterator b, 
                  vector<int>::iterator e)
{
    cout << "           Original vector: ";

    for(vector<int>::iterator p=b; p!=e; ++p)
        cout << setw(3) << *p;

    /* Alternate approach:
    *  vector<int>::iterator p = b;
    *  while(p<e)
    *      cout << setw(3) << *(p++);*/

    cout << endl;
    return;
}

void print_vector_odd(const vector<int> &v)
{
    cout << " Odd numbers in the vector: ";
    for(int i=0; i<v.size(); ++i)
        if(odd(v[i]))
            cout << setw(3) << v[i];
    cout << endl;
    return;
}

void print_vector_even(const vector<int> &v)
{
    cout << "Even numbers in the vector: ";
    for(int i=0; i<v.size(); ++i)
        if(!odd(v[i]))
            cout << setw(3) << v[i];
    cout << endl;
    return;
}
