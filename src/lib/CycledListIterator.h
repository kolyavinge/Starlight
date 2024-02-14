#pragma once

#include <lib/Object.h>
#include <lib/List.h>

template<class T>
class CycledListIterator : public Object
{
    List<T>& _list;
    int _index;

public:
    CycledListIterator(List<T>& list) :
        _list(list)
    {
        _index = 0;
    }

    T& GetCurrentItem()
    {
        return _list[_index];
    }

    void Prev()
    {
        _index--;
        if (_index == -1) _index = _list.Count() - 1;
    }

    void Next()
    {
        _index++;
        if (_index == _list.Count()) _index = 0;
    }

    void Reset()
    {
        _index = 0;
    }
};
