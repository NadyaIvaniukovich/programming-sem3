#include "shape.h"


Shape::Shape(){}


Shape::~Shape(){}

double Shape :: areaToPerimeter()const
{
    return area()/perimeter();
}
