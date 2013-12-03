#pragma once
#include "transformation.h"

class Shape
{
public:
    Shape();
    ~Shape();
    virtual double perimeter()const = 0;
    virtual double area()const = 0;
    virtual double areaToPerimeter()const;
    virtual Shape* apply(Transformation &);
};

