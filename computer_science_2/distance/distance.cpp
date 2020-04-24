/* Nina Hudak
 * Homework 4: Randomly generate 50 points where x and y are
 * both between -5.0 and 5.0 inclusive. Output pair of points
 * with largest distance between.
 * February 18, 2019
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int SIZE = 50;

struct Point
{
    double x;
    double y;
};

double random(unsigned long int &seed);

void fill_array(Point arr[]);

double distance(Point p1, Point p2);

double get_max_distance(Point arr[], Point &p1, Point &p2);

void print_points(Point p1, Point p2, double max_distance);

int main()
{
    Point array_points[SIZE];
    Point p1, p2;
    double max_distance;

    fill_array(array_points);
    max_distance = get_max_distance(array_points, p1, p2);
    print_points(p1, p2, max_distance);

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

void fill_array(Point arr[])
{
    unsigned long int seed;

    for(int i=0; i<SIZE; ++i)
    {
        arr[i].x = -5 + 10*random(seed);
        arr[i].y = -5 + 10*random(seed);
    }

    return;
}

double distance(Point p1, Point p2)
{
    double distance = sqrt(pow(p2.x-p1.x,2) + pow(p2.y-p1.y,2));
    return distance;
}

double get_max_distance(Point arr[], Point &p1, Point &p2)
{
    double max_distance = 0.0;
    Point p1temp, p2temp;

    for(int i=0; i<SIZE; ++i)
    {
        p1temp.x = arr[i].x;
        p1temp.y = arr[i].y;
        for(int j=i+1; j<SIZE-1; ++j)
        {
            p2temp.x = arr[j].x;
            p2temp.y = arr[j].y;
            if(distance(p1temp, p2temp) > max_distance)
            {
                p1.x = p1temp.x;
                p1.y = p1temp.y;
                p2.x = p2temp.x;
                p2.y = p2temp.y;
                max_distance = distance(p1, p2);
            }
        }
    }

    return max_distance;
}

void print_points(Point p1, Point p2, double max_distance)
{
    cout << setprecision(5) << fixed << showpoint;
    cout << "Point 1: (" << setw(8) << p1.x;
    cout << ", " << setw(8) <<  p1.y << ")\n";
    cout << "Point 2: (" << setw(8) << p2.x; 
    cout << ", " << setw(8) << p2.y << ")\n";
    cout << "Distance: " << setw(8) << max_distance << endl;
    return;
}
