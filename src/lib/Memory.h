#pragma once

#include <malloc.h>
#include <cstring>
#include <lib/Exceptions.h>

class MemoryAllocationException : public Exception {};

class Memory
{
public:
    template<class T>
    static T* AllocAndZero(int itemsCount)
    {
        if (itemsCount <= 0) throw ArgumentException();
        T* result = (T*)malloc(itemsCount * sizeof(T));
        if (result == nullptr) throw MemoryAllocationException();
        Zero<T>(result, itemsCount);

        return result;
    }

    template<class T>
    static void Zero(T* source, int itemsCount)
    {
        if (itemsCount <= 0) throw ArgumentException();
        std::memset(source, 0, itemsCount * sizeof(T));
    }

    template<class T>
    static void Copy(const T* source, T* dest, int itemsCount)
    {
        if (itemsCount < 0) throw ArgumentException();
        std::memcpy(dest, source, itemsCount * sizeof(T));
    }

    static void Release(void* source)
    {
        free(source);
    }

    template<class T>
    static void Resize(T*& source, int currentItemsCount, int newItemsCount)
    {
        T* newSource = AllocAndZero<T>(newItemsCount);
        Copy<T>(source, newSource, currentItemsCount);
        Release(source);
        source = newSource;
    }
};
