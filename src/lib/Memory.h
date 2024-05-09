#pragma once

#include <lib/Exceptions.h>
#include <lib/StdFuncs.h>

class MemoryAllocationException : public Exception {};

class Memory
{
public:
    template<class T>
    static T* AllocAndZero(int itemsCount)
    {
        if (itemsCount <= 0) throw ArgumentException();
        T* result = (T*)StdFuncs::Malloc(itemsCount * sizeof(T));
        if (result == nullptr) throw MemoryAllocationException();
        Zero<T>(result, itemsCount);

        return result;
    }

    template<class T>
    static void Zero(T* source, int itemsCount)
    {
        if (itemsCount <= 0) throw ArgumentException();
        StdFuncs::MemSet(source, 0, itemsCount * sizeof(T));
    }

    template<class T>
    static void Copy(const T* source, T* dest, int itemsCount)
    {
        if (itemsCount < 0) throw ArgumentException();
        StdFuncs::MemCpy(dest, source, itemsCount * sizeof(T));
    }

    static void Release(void* source)
    {
        StdFuncs::Free(source);
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
