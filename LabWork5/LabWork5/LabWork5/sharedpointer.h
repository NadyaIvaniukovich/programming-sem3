#pragma once

template<class T>

class SharedPointer
{
    T* pointer;
    int count;
    SharedPointer<T>(const SharedPointer<T> &);
    SharedPointer<T> & operator =(const SharedPointer<T> &);
public:
    SharedPointer();
    SharedPointer(T* pointer);    
    ~SharedPointer();
    T & operator *();
    T * operator ->();
    explicit operator bool();
};

