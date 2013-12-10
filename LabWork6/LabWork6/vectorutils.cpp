#include "vectorutils.h"
#include "stdafx.h"

int scalarProduct(vector<int> vector1,vector<int> vector2)
{
    int result = 0;
    for (int i = 0; i < vector1.size(); i++)
    {
        result += vector1[i]*vector2[i];
    }
    return result;
}

bool areCollinear(vector<int> vector1, vector<int> vector2)
{
    int product11 = scalarProduct(vector1,vector1),
        product22 = scalarProduct(vector2,vector2),
        product12 = scalarProduct(vector1,vector2);
    return product11*product22 == product12*product12;
}

bool areOrthogonal(vector<int> vector1, vector<int> vector2)
{
    return !scalarProduct(vector1,vector2);
}