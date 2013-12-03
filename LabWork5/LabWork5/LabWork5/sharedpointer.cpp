#include "sharedpointer.h"

template<class T>
SharedPointer<T> :: SharedPointer()
{
    pointer = new T();
    count = 1;
}

template<class T>
SharedPointer<T> :: SharedPointer(T* ptr): pointer(ptr),count(1){}


template<class T> 
SharedPointer<T> :: ~SharedPointer()
{
    --count;
    if(count == 0)
        delete pointer;
}

template<class T> 
SharedPointer<T> :: SharedPointer(const SharedPointer<T> & ptr)
{
    pointer = ptr.pointer;
    count = ++ptr.count;
}

template<class T> 
SharedPointer<T> & SharedPointer<T> :: operator =(const SharedPointer<T> & ptr)
{
    if(this != &ptr)
    {
        --count;
        if(count == 0)
            delete pointer;
        pointer = ptr.pointer;
        count = ++ptr.count;
    }
}

template<class T> 
T & SharedPointer<T> :: operator *()
{
    return *pointer;
}

template<class T> 
T * SharedPointer<T> :: operator ->()
{
    return pointer;
}

template<class T> 
explicit SharedPointer<T> :: operator bool()
{
    return pointer != 0;
}