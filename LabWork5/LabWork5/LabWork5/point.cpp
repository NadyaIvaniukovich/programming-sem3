#include "point.h"
#include<math.h>


Point :: Point():x(0),y(0){}

Point :: ~Point(){}

Point :: Point(int x, int y):x(x),y(y){}

Point :: Point(const Point & point):x(point.x), y(point.y){}

int Point :: getX()
{
    return x;
}
void Point :: setX(int x_)
{
    x = x_;
}
int Point :: getY()
{
    return y;
}
void Point :: setY(int y_)
{
    y = y_;
}

Point & Point :: operator = (const Point & point)
{
    x = point.x;
    y = point.y;
    return *this;
}

double distance(Point a1, Point a2)
{
    return sqrt((double)((a1.getX() - a2.getX()) * (a1.getX() - a2.getX()) + (a1.getY() - a2.getY()) * (a1.getY() - a2.getY())));
}