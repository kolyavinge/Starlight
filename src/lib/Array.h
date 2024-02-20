#pragma once

#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <lib/Memory.h>
#include <lib/IArray.h>

template<class T, int Count>
class Array : public Object, public IArray<T>
{
    T _items[Count] = {};

public:
    Array() {}

    T& operator[](int index) override
    {
        CheckBounds(index);
        return _items[index];
    }

    int GetCount() override
    {
        return Count;
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
