#pragma once

#include <lib/Object.h>
#include <lib/Array.h>

template<class T, int Count>
class CycledArrayIterator : public Object
{
    Array<T, Count>& _array;
    int _index;

public:
    CycledArrayIterator(Array<T, Count>& array) :
        _array(array)
    {
        _index = 0;
    }

    T& GetCurrentItem()
    {
        return _array[_index];
    }

    void Prev()
    {
        _index--;
        if (_index == -1) _index = Count - 1;
    }

    void Next()
    {
        _index++;
        if (_index == Count) _index = 0;
    }

    void Reset()
    {
        _index = 0;
    }
};
