#pragma once

class Object
{
public:
    static bool ReferenceEquals(Object& x, Object& y);

    virtual ~Object();

    virtual bool Equals(Object& x);
    virtual int GetHashCode();
};
