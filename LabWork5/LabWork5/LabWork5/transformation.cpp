#include "transformation.h"

Transformation :: Transformation(){}

Transformation :: Transformation(int mtrx[2][2], int vctr[2])
{
    for (int i = 0; i < 2; i++)
    {
        vector[i] = vctr[i];
        for (int j = 0; j < 2; j++)
            matrix[i][j] = mtrx[i][j];
    }
}

Transformation :: ~Transformation(){}

int Transformation :: determinant()
{
    return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];
}

Point Transformation :: apply(Point & point)
{
    Point result;
    result.setX(point.getX() * matrix[0][0] + point.getY() * matrix[0][1] + vector[0]);
    result.setY(point.getX() * matrix[1][0] + point.getY() * matrix[1][1] + vector[1]);
    return result;
}