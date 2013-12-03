#pragma once
#include<iostream>

class TransformException: public std::exception
{
    const char* mywhat;
public:
    TransformException(const char[]);
    const char* what()const;
    ~TransformException();
};

