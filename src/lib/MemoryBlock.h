#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/Memory.h>

template<class T>
class MemoryBlock : public Object
{
    static const int _initCapacity = 16;

    T* _items;
    int _count;
    int _capacity;

public:
    MemoryBlock() : MemoryBlock(_initCapacity) { }

    MemoryBlock(int capacity)
    {
        if (capacity < 0) throw new ArgumentException();
        _count = 0;
        _capacity = capacity;
        _items = Memory::Alloc<T>(_capacity);
    }

    MemoryBlock(const MemoryBlock<T>& copy)
    {
        _items = nullptr;
        Set(copy);
    }

    ~MemoryBlock()
    {
        Memory::Release(_items);
        _items = nullptr;
    }

    MemoryBlock<T>& operator=(const MemoryBlock<T>& copy)
    {
        Set(copy);
        return *this;
    }

    T& operator[](int index)
    {
        CheckBounds(index);
        return _items[index];
    }

    void ResizeIfNeeded(int addedCount)
    {
        int newCount = _count + addedCount;
        if (newCount > _capacity)
        {
            _capacity = 2 * newCount;
            Memory::Resize<T>(_items, _capacity);
        }
        _count = newCount;
    }

    void Append(MemoryBlock<T>& range)
    {
        Memory::Copy<T>(range.GetPointer(), _items + _count, range.Count());
    }

    T* GetPointer()
    {
        return _items;
    }

    int GetCount()
    {
        return _count;
    }

    int GetCapacity()
    {
        return _capacity;
    }

    void Clear()
    {
        _count = 0;
    }

private:
    void Set(const MemoryBlock<T>& copy)
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

    void CheckBounds(int index)
    {
        bool inBounds = 0 <= index && index < _count;
        if (!inBounds) throw IndexOutOfBoundsException();
    }
};
