#pragma once

class Point
{
    int x, y;
public:
    Point();
    Point(int x, int y);
    Point(const Point & point);
    ~Point();
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    Point & operator = (const Point & point);
};

double distance(Point a1, Point a2);