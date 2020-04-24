/* Nina Hudak
 * Lab 4: Obtain random values for x and y between 0 and 1
 * February 13, 2019
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int SIZE = 1000;

struct Point;

double random(unsigned long int &seed);

void fill_array(Point *pointer, double x_arr[], double y_arr[]);

void get_min(double &x_min, double &y_min, double x_arr[], double y_arr[]);

void print_points(double x_min, double y_min, double x_arr[], double y_arr[]);

int main()
{
    unsigned long int seed;
    double x_min, y_min;
    Point *pointer;
    double x_arr[1000];
    double y_arr[1000];

    fill_array(pointer, x_arr, y_arr);
    get_min(x_min, y_min, x_arr, y_arr);
    print_points(x_min, y_min, x_arr, y_arr);

    return 0;
}

struct Point
{
    double x;
    double y;
};

double random(unsigned long int &seed)
{
    const int MODULUS = 15749;
    const int MULTIPLIER = 69069;
    const int INCREMENT = 1;
    seed = ((MULTIPLIER*seed)+INCREMENT)%MODULUS;
    return double(seed)/MODULUS;
}

void fill_array(Point *pointer, double x_arr[], double y_arr[])
{
    pointer = new Point;
    unsigned long int seed;

    for(int i=0; i<SIZE; ++i)
    {
        (*pointer).x = random(seed);
        (*pointer).y = random(seed);
        x_arr[i] = (*pointer).x;
        y_arr[i] = (*pointer).y;
    }

    return;
}

void get_min(double &x_min, double &y_min, double x_arr[], double y_arr[])
{
    x_min = 2;
    y_min = 2;

    for(int i=0; i<SIZE; ++i)
    {
        if(x_arr[i] < x_min)
            x_min = x_arr[i];
        if(y_arr[i] < y_min)
            y_min = y_arr[i];
    }

    return;
}

void print_points(double x_min, double y_min, double x_arr[], double y_arr[])
{
    cout << setprecision(5) << fixed << showpoint;
    cout << "Smallest x points:\n";

    for(int i=0; i<SIZE; ++i)
    {
        if(x_arr[i] == x_min)
        {
            cout << "(" << setw(7) << x_arr[i] << ", ";
            cout << setw(7) << y_arr[i] << ")\n";
        }
    }

    cout << "\nSmallest y points:\n";

    for(int i=0; i<SIZE; ++i)
    {
        if(y_arr[i] == y_min)
        {
            cout << "(" << setw(7) << x_arr[i] << ", ";
            cout << setw(7) << y_arr[i] << ")\n";
        }
    }

    return;
}
