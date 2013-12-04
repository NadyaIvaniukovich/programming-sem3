#pragma once

template<class T>

class SharedPointer
{
    T* pointer;
    int count;
public:
    SharedPointer<T> & operator =(const SharedPointer<T> &);
    SharedPointer<T>(const SharedPointer<T> &);
    SharedPointer();
    SharedPointer(T* pointer);    
    ~SharedPointer();
    T & operator *();
    T * operator ->();
    explicit operator bool();
};

