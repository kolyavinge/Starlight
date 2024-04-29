#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>

template<class T>
class CycledIterator : public Object
{
    Collection<T>& _items;
    int _index;

public:
    CycledIterator(Collection<T>& items) :
        _items(items)
    {
        _index = 0;
    }

    T& GetCurrentItem()
    {
        return _items[_index];
    }

    void Prev()
    {
        _index--;
        if (_index == -1) _index = _items.GetCount() - 1;
    }

    void Next()
    {
        _index++;
        if (_index == _items.GetCount()) _index = 0;
    }

    void Reset()
    {
        _index = 0;
    }
};
