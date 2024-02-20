#pragma once

template<class T>
class IArray
{
public:
    virtual T& operator[](int index) = 0;
    virtual int GetCount() = 0;
};
