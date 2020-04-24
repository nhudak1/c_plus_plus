/* Nina Hudak
 * Trapez header file: trapez.h
 */

#undef TRAPEZ_H
#ifndef TRAPEZ_H
#define TRAPEZ_H

#include "polygon.h"

class Trapez: public Polygon
{
    public:
        double area();
        void assign_trapez_height(double h);
    private:
        double height;
};
#endif
