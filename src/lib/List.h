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
        if (capacity <= 0) throw ArgumentException();
        _count = 0;
        _capacity = capacity;
        _items = Memory::Alloc<T>(_capacity);
    }

    List(const List<T>& copy)
    {
        _items = nullptr;
        Set(copy);
    }

    ~List()
    {
        Memory::Release(_items);
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

    void InitAll(T initValue)
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
        Memory::Copy<T>(range._items, _items + _count, range.Count());
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

    void PrepareEnoughCapacity(int enoughCapacity)
    {
        if (enoughCapacity <= 0) throw ArgumentException();
        if (_capacity > enoughCapacity) return;
        _capacity = enoughCapacity;
        Memory::Resize<T>(_items, _count, _capacity);
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
        _items = Memory::Alloc<T>(_capacity);
        Memory::Copy<T>(copy._items, _items, _capacity);
    }

    void ResizeIfNeeded(int addedCount = 1)
    {
        bool resize = false;
        while (_count + addedCount >= _capacity)
        {
            _capacity *= 2;
            resize = true;
        }
        if (resize)
        {
            Memory::Resize<T>(_items, _count, _capacity);
        }
    }

    void CheckBounds(int index, int count)
    {
        bool inBounds = 0 <= index && index < count;
        if (!inBounds) throw IndexOutOfBoundsException();
    }
};
