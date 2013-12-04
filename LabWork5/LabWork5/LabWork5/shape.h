#pragma once
#include "transformation.h"
#include "sharedpointer.h"

class Shape
{
public:
    Shape();
    ~Shape();
    virtual double perimeter()const = 0;
    virtual double area()const = 0;
    virtual double areaToPerimeter()const;
    virtual SharedPointer<Shape> apply(Transformation &);
};

