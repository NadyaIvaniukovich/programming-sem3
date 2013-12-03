#include "transformexception.h"


TransformException :: TransformException(const char str[])
{
    mywhat = str;
}

const char* TransformException:: what()const
{
    return mywhat;
}


TransformException :: ~TransformException(){}
