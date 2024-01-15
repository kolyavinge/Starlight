#pragma once

#include <malloc.h>
#include <cstring>
#include <lib/Exceptions.h>

class Memory
{
public:
    template<class T>
    static T* Alloc(unsigned int itemsCount)
    {
        void* result = malloc(itemsCount * sizeof(T));
        if (result == nullptr) throw MemoryAllocationException();

        return (T*)result;
    }

    template<class T>
    static void Zero(T* source, unsigned int itemsCount)
    {
        std::memset(source, 0, itemsCount * sizeof(T));
    }

    template<class T>
    static void Copy(const T* source, T* dest, unsigned int itemsCount)
    {
        std::memcpy(dest, source, itemsCount * sizeof(T));
    }

    static void Release(void* source)
    {
        free(source);
    }

    template<class T>
    static void Resize(T*& source, unsigned int currentItemsCount, unsigned int newItemsCount)
    {
        T* newSource = Alloc<T>(newItemsCount);
        Copy<T>(source, newSource, currentItemsCount);
        Release(source);
        source = newSource;
    }
};
