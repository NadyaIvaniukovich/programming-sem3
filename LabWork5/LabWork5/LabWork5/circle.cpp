#include "circle.h"
#define _USE_MATH_DEFINES
#include <cmath>


Circle :: Circle():radius(0){}

Circle :: Circle(int r, Point c): radius(r), center(c){}

Circle :: ~Circle(){}

double Circle :: perimeter()const
{
    return 2*M_PI*radius;
}

double Circle :: area()const
{
    return M_PI*radius*radius;
}

int Circle :: getRadius()
{
    return radius;
}
void Circle :: setRadius(int r)
{
    radius = r;
}
Point Circle :: getCenter()
{
    return center;
}

void Circle :: setCenter(Point c)
{
    center = c;
}