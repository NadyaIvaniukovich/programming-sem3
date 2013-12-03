#include<iostream>
#include<vector>
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
#include "sharedpointer.h"

using namespace std;



int main()
{
    vector<SharedPointer<Shape>> shapes, results;
    shapes.push_back(SharedPointer<Shape>(new Triangle(Point(1,0), Point(0,0), Point(0,2))));
    shapes.push_back(SharedPointer<Shape>(new Rectangle(Point(1,0), Point(0,0), Point(0,2))));
    shapes.push_back(SharedPointer<Shape>(new Circle(1,Point(0,0))));
    vector<Transformation> transformations;
    int matrix1[2][2] = {{0,0},{0,0}}, vector1[2] = {1,1},
        matrix2[2][2] = {{2,0},{0,2}}, vector2[2] = {0,0};
    transformations.push_back(Transformation(matrix1,vector1));
    transformations.push_back(Transformation(matrix2,vector2));
    
    vector<SharedPointer<Shape>> :: iterator iterator = shapes.begin();
    while( iterator != shapes.end())
    {
        vector<Transformation> :: iterator transformation = transformations.begin();
        while( transformation != transformations.end())
            results.push_back((*iterator)->apply(*transformation));   
    }

    system("pause");
    return 0;
}