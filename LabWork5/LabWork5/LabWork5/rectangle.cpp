#include "rectangle.h"


Rectangle :: Rectangle(){}

Rectangle :: Rectangle(Point a, Point b, Point c)
{
    int abX = b.getX() - a.getY(), 
        abY = b.getY() - a.getY(),
        bcX = c.getX() - b.getX(), 
        bcY = c.getY() - b.getY();
    if((abX*bcX + abY*bcY) != 0)
        throw IllegalArgumentException("Angle abc is not right.");
    vertexA = a;
    vertexB = b;
    vertexC = c;    
}

Rectangle :: ~Rectangle(){}

double Rectangle :: perimeter()const
{
    return 2*distance(vertexC,vertexB) + 2*distance(vertexA,vertexB);
}

double Rectangle :: area()const
{
    return distance(vertexC,vertexB)* distance(vertexA,vertexB);
}

Point Rectangle :: getVertexA()
{
    return vertexA;
}

Point Rectangle :: getVertexB()
{
    return vertexB;
}

Point Rectangle :: getVertexC()
{
    return vertexC;
}

Shape* Rectangle :: apply(Transformation & t)
{
    try {
        return new Rectangle(t.apply(vertexA), t.apply(vertexB), t.apply(vertexC));
    }
    catch(IllegalArgumentException & e)
    {
        throw TransformException("Non-move transformations are not supported for rectangles");
    }
}