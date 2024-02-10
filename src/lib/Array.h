#pragma once

#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <lib/Memory.h>

template<class T, int Count>
class Array : public Object
{
    T _items[Count] = {};

public:
    static const int Count = Count;

    Array() {}

    T& operator[](int index)
    {
        CheckBounds(index);
        return _items[index];
    }

    void InitAll(T initValue)
    {
        for (int i = 0; i < Count; i++)
        {
            _items[i] = initValue;
        }
    }

    void InitRange(int startIndex, int endIndex, T value)
    {
        for (int i = startIndex; i <= endIndex; i++)
        {
            _items[i] = value;
        }
    }

    void InitZero()
    {
        Memory::Zero<T>(_items, Count);
    }

private:
    void CheckBounds(int index)
    {
        bool inBounds = 0 <= index && index < Count;
        if (!inBounds) throw IndexOutOfBoundsException();
    }
};
