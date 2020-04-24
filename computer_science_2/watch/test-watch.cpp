/* Nina Hudak
 * Lab 11: Write a program that initializes int vector v
 * of size 10000 with rand ints each in range [0,10] and
 * determines, using class watch, if sorting the vector using
 * function sort() is better than sorting the vector using
 * function bubble_sort() given below:
 * April 10, 2019
 */

#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include "watch.h"

const int SIZE = 10000;
unsigned long int seed = (unsigned long int)time(0);

using namespace std;

double random(unsigned long int &seed);
void initialize(vector<int> &v);
void bubble_sort(vector<int> &v);
void bubble_sort_rec(vector<int> &v);
void print_time(Watch my_watch);

int main()
{
    Watch my_watch;
    vector<int> v_1, v_2;

    cout << setprecision(10) << fixed << showpoint;

    initialize(v_1);
    v_2 = v_1;
    cout << endl;

    my_watch.start();
    bubble_sort(v_1);
    my_watch.stop();

    cout << "Bubble Sort:" << endl;
    print_time(my_watch);

    my_watch.start();
    bubble_sort_rec(v_2);
    my_watch.stop();

    cout << "\nBubble Sort Recursive: " << endl;
    print_time(my_watch);
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
        v.push_back(int(11*random(seed)));
}

void bubble_sort(vector<int> &v)
{
    int temp;
    for(int k=1; k<v.size()-1; ++k)
        for(int j=0; j<v.size()-1-k; ++j)
            if(v[j]>v[j+1])
            {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
}

void bubble_sort_rec(vector<int> &v)
{
    int count=0, min, index, temp;
    
    do
    {
        min = v[count];
        for(int k=count; k<v.size(); ++k)
            if(v[k] < min)
            {
                min = v[k];
                index = k;
            }
        temp = v[count];
        v[count] = min;
        v[index] = temp;
        ++count;
    }   while(count<v.size());
}

void print_time(Watch my_watch)
{
    cout << "Seconds passed: " << my_watch.seconds() << endl;
}
