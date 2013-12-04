#pragma once
#include "shape.h"


class Triangle: public Shape
{
    Point vertexA,vertexB,vertexC;
public:
    Triangle();
    Triangle(Point, Point, Point);
    ~Triangle();
    double perimeter()const;
    double area()const;
    Point getVertexA();
    void setVertexA(Point);
    Point getVertexB();
    void setVertexB(Point);
    Point getVertexC();
    void setVertexC(Point);
    SharedPointer<Shape> apply(Transformation &);
};

