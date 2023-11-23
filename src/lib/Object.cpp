#include "lib/Object.h"

Object::~Object() {}

bool Object::ReferenceEquals(Object& x, Object& y)
{
    return (&x) == (&y);
}

bool Object::Equals(Object& x)
{
    return ReferenceEquals(*this, x);
}

int Object::GetHashCode()
{
    return (int)(long long)this;
}
