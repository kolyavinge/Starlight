#pragma once

#include <lib/Exceptions.h>
#include <lib/Object.h>
#include <lib/Memory.h>

template<class T>
class List : public Object
{
    static const int _initCapacity = 16;

    T* _items;
    int _count;
    int _capacity;

public:
    List() : List(_initCapacity) {}

    List(int capacity)
    {
        _count = 0;
        _capacity = capacity;
        _items = (T*)Memory::Alloc(_capacity * sizeof(T));
    }

    List(const List<T>& copy)
    {
        _items = nullptr;
        Set(copy);
    }

    ~List()
    {
        Memory::Release(_items);
        _items = nullptr;
    }

    List<T>& operator=(const List<T>& copy)
    {
        Set(copy);
        return *this;
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

    void AddRange(List<T>& range)
    {
        ResizeIfNeeded(range.Count());
        Memory::Copy(range._items, _items + _count, sizeof(T) * range.Count());
        _count += range.Count();
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

    T* GetItemsPointer()
    {
        return _items;
    }

private:
    void Set(const List<T>& copy)
    {
        _count = copy._count;
        _capacity = copy._capacity;
        if (_items != nullptr)
        {
            Memory::Release(_items);
        }
        _items = (T*)Memory::Alloc(_capacity * sizeof(T));
        Memory::Copy(copy._items, _items, _capacity * sizeof(T));
    }

    void ResizeIfNeeded(int addedCount = 1)
    {
        while (_count + addedCount >= _capacity)
        {
            _capacity *= 2;
        }
        Memory::Resize((void*&)_items, _capacity * sizeof(T));
    }

    void CheckBounds(int index, int count)
    {
        bool inBounds = 0 <= index && index < count;
        if (!inBounds) throw IndexOutOfBoundsException();
    }
};
