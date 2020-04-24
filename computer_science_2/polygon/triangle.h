/* Nina Hudak
 * Header file for derived class: triangle.h
 */

#undef TRIANGLE_H
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

using namespace std;

class Triangle: public Polygon
{
    public:
        double area();
        double return_base();
        double return_height();
        void print_base();
        void print_height();
};

#endif

