#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>

template<class T>
class CycledArrayIterator : public Object
{
    IArray<T>& _array;
    int _index;

public:
    CycledArrayIterator(IArray<T>& array) :
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
        if (_index == -1) _index = _array.GetCount() - 1;
    }

    void Next()
    {
        _index++;
        if (_index == _array.GetCount()) _index = 0;
    }

    void Reset()
    {
        _index = 0;
    }
};
