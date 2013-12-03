#pragma once
#include "shape.h"
#include "point.h"

class Circle: public Shape
{
    int radius;
    Point center;
public:
    Circle();
    Circle(int, Point);
    ~Circle();
    double perimeter()const;
    double area()const;
    int getRadius();
    void setRadius(int);
    Point getCenter();
    void setCenter(Point);
};

