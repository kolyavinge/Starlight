#pragma once

#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <lib/Memory.h>

template<class T>
class List : public Object
{
    static const unsigned int InitCapacity = 16;

    T* _items;
    int _count;
    int _capacity;

public:
    List() : List(InitCapacity) {}

    List(int capacity)
    {
        _count = 0;
        _capacity = capacity;
        _items = (T*)Memory::Alloc(_capacity * sizeof T);
    }

    ~List()
    {
        Memory::Release(_items);
    }

    T& operator[](int index)
    {
        CheckBounds(index, _count);
        return _items[index];
    }

    int Count()
    {
        return _count;
    }

    void InitItems(T initValue)
    {
        for (int i = 0; i < _count; i++)
        {
            _items[i] = initValue;
        }
    }

    void Add(T value)
    {
        ResizeIfNeeded();
        _items[_count] = value;
        _count++;
    }

    void Insert(int index, T value)
    {
        CheckBounds(index, _count + 1);
        ResizeIfNeeded();
        for (int i = _count; i > index; i--)
        {
            _items[i] = _items[i - 1];
        }
        _items[index] = value;
        _count++;
    }

    void RemoveAt(int index)
    {
        CheckBounds(index, _count);
        for (int i = index; i < _count - 1; i++)
        {
            _items[i] = _items[i + 1];
        }
        _count--;
    }

    void Clear()
    {
        _count = 0;
    }

private:
    void ResizeIfNeeded()
    {
        if (_count + 1 > _capacity)
        {
            _capacity *= 2;
            Memory::Resize((void*&)_items, _capacity * sizeof T);
        }
    }

    void CheckBounds(int index, int count)
    {
        bool inBounds = 0 <= index && index < count;
        if (!inBounds) throw IndexOutOfBoundsException();
    }
};
