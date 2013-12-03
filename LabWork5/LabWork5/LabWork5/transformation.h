#pragma once
#include "point.h"

class Transformation
{
    int matrix[2][2], vector[2];
public:
    Transformation();
    Transformation(int matrix[2][2],int vector[2]);
    ~Transformation();
    int determinant();
    Point apply(Point &);
};

