#pragma once
#include "shape.h"
#include "illegalargumentexception.h"
#include "transformexception.h"


class Rectangle: public Shape
{
    Point vertexA, vertexB, vertexC;
public:
    Rectangle();
    Rectangle(Point, Point, Point);
    ~Rectangle();
    double perimeter()const;
    double area()const;
    Point getVertexA();
    Point getVertexB();
    Point getVertexC();
    Shape* apply(Transformation&);
};

