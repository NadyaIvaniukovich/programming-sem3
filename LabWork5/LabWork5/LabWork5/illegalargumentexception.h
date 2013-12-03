#pragma once
#include<iostream>

class IllegalArgumentException: public std::exception
{
    const char* mywhat;
public:
    IllegalArgumentException(const char[]);
    const char* what()const;
    ~IllegalArgumentException();
};

