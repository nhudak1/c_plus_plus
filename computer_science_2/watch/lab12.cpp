/* Nina Hudak
 * Lab 12: Write a program that initializes int vector v
 * of size 10000 with rand ints each in range [0,10], sorts with
 * bubble_sort(), and compares the times using two different methods
 * April 24, 2019
 */

#include <iostream>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <vector>
#include <algorithm>
#include "watch.h"

const int SIZE = 10000;
unsigned long int seed = (unsigned long int)time(0);

using namespace std;
using namespace std::chrono;

double random(unsigned long int &seed);
void initialize(vector<int> &v);
void bubble_sort(vector<int> &v);
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

    cout << "Time with Watch class:" << endl;
    print_time(my_watch);

    auto start = system_clock::now();
    bubble_sort(v_2);
    auto end = system_clock::now();
    duration<double> seconds = end-start;

    cout << "\nTime with built-in function: " << endl;
    cout << "Seconds passed: " << seconds.count() << endl;
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

void print_time(Watch my_watch)
{
    cout << "Seconds passed: " << my_watch.seconds() << endl;
}
