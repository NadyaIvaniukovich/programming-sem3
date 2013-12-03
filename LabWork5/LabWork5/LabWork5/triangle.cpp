#include "triangle.h"
#include <math.h>


Triangle :: Triangle(){}

Triangle :: Triangle(Point a, Point b, Point c): vertexA(a), vertexB(b), vertexC(c){}

Triangle :: ~Triangle(){}

double Triangle :: perimeter()const
{
    return distance(vertexA,vertexB) + distance(vertexA,vertexC) + distance(vertexB,vertexC);
}

double Triangle :: area()const
{
    return sqrt(perimeter()/2 * (perimeter()/2 - distance(vertexA,vertexB)) * (perimeter()/2 - distance(vertexA,vertexC))
        * (perimeter()/2 - distance(vertexB,vertexC)));
}

Point Triangle :: getVertexA()
{
    return vertexA;
}

void Triangle :: setVertexA(Point a)
{
    vertexA = a;
}

Point Triangle :: getVertexB()
{
    return vertexB;
}

void Triangle :: setVertexB(Point b)
{
    vertexB = b;
}

Point Triangle :: getVertexC()
{
    return vertexC;
}

void Triangle :: setVertexC(Point c)
{
    vertexC = c;
}

Shape* Triangle :: apply(Transformation & t)
{
    return new Triangle(t.apply(vertexA),t.apply(vertexB),t.apply(vertexC));
}