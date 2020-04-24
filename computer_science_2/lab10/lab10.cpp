/* Nina Hudak
 * Lab 10: Write a program that declares struct record, declares
 * and initializes vector of SIZE = 5 of such records with rand
 * ints in range [0,6), doubles in range [0,2), and characters
 * in range ['a','z'], prints the original vector, then prints
 * the vector with fields sorted by ints in the desc. order, then
 * prints the vector sorted by doubles in the asc. order, and
 * finally prints the vector with fields sorted by characters in
 * the desc. order.
 * April 3, 2019
 */

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 5;
unsigned long int seed = (unsigned long int)time(0);

struct Record{
    int n;
    double x;
    char ch;
};

double random(unsigned long int &seed);
void initialize(vector<Record> &v);
void print_vector(vector<Record> &v);
inline bool cmp_str_int_desc(const Record &p, const Record &q);
inline bool cmp_str_dbl_asc(const Record &p, const Record &q);
inline bool cmp_str_char_desc(const Record &p, const Record &q);

int main()
{
    vector<Record> v;
    initialize(v);

    cout << endl;
    cout << "Vector:" << endl;
    print_vector(v);

    sort(v.begin(), v.end(), cmp_str_int_desc);
    cout << "Sorting by integers in descending order:" << endl;
    print_vector(v);

    sort(v.begin(), v.end(), cmp_str_dbl_asc);
    cout << "Sorting by doubles in ascending order:" << endl;
    print_vector(v);

    sort(v.begin(), v.end(), cmp_str_char_desc);
    cout << "Sorting by characters in descending order:" << endl;
    print_vector(v);

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

void initialize(vector<Record> &v)
{
    cout << setprecision(4) << fixed << showpoint;
    Record temp;
    for(int i=0; i<SIZE; ++i)
    {
        temp.n = int(6*random(seed));
        temp.x = 2*random(seed);
        temp.ch = char(97 + 26*random(seed));
        v.push_back(temp);
    }
}

void print_vector(vector<Record> &v)
{
    cout << "=================================================" << endl;
    for(int i=0; i<SIZE; ++i)
    {
        cout << setw(3) << v[i].n;
        cout << setw(7) << v[i].x;
        cout << setw(3) << v[i].ch << endl;
    }
    cout << endl;
}

inline bool cmp_str_int_desc(const Record &p, const Record &q)
{
    return p.n > q.n;
}

inline bool cmp_str_dbl_asc(const Record &p, const Record &q)
{
    return p.x < q.x;
}

inline bool cmp_str_char_desc(const Record &p, const Record &q)
{
    return p.ch > q.ch;
}

