#pragma once

class Utils
{
public:
    template<class T>
    static void Swap(T& a, T& b)
    {
        T tmp = a;
        a = b;
        b = tmp;
    }
};
