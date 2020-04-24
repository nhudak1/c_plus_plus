/* Nina Hudak
 * Watch class implementation file: watch.cpp
 * April 10, 2019
 */

#include <iostream>
#include <cstdlib>
#include "watch.h"

using namespace std;

Watch::Watch()
{
    ticks_passed = clock();
}

void Watch::start()
{
    ticks_passed = clock();
}

void Watch::stop()
{
    ticks_passed = clock() - ticks_passed;
    if(ticks_passed == clock_t(-1))
    {
        cout << "clock overflow" << endl;
        exit(1);
    }
}

void Watch::delay(int duration)
{
    for(int i=0; i<duration; ++i);
}

float Watch::seconds()
{
    return float(ticks_passed)/CLOCKS_PER_SEC;
}

float Watch::minutes()
{
    return float(ticks_passed)/CLOCKS_PER_SEC/60;
}

float Watch::hours()
{
    return float(ticks_passed)/CLOCKS_PER_SEC/60/60;
}
