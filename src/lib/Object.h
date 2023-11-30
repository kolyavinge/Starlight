#pragma once

class Object
{
public:
    static bool ReferenceEquals(Object& x, Object& y);

    virtual ~Object();

    bool virtual Equals(Object& x);
    int virtual GetHashCode();
};
