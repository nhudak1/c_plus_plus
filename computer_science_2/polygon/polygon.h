/* Nina Hudak
 * Header file for base class: polygon.h
 */

using namespace std;

//#undef WATCH_H
#ifndef WATCH_H
#define WATCH_H

class Polygon
{
    public:
        void assign_values(double a, double b);
    protected:
        double side_a, side_b;
};

#endif
