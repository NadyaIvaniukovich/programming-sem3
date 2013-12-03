#include "illegalargumentexception.h"


IllegalArgumentException :: IllegalArgumentException(const char str[])
{
    mywhat = str;
}

const char* IllegalArgumentException :: what()const
{
    return mywhat;
}

IllegalArgumentException :: ~IllegalArgumentException(){}
