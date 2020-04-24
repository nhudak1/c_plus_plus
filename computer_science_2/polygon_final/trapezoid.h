//Header file for class trapezoid: trapezoid.h


using namespace std;

#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "polygon.h"

class Trapezoid: public Polygon
{
    public:
        void assign_trapez_height(double h);
        double area();
    private:
        double height;
};

#endif
