#pragma once

class StdFuncs
{
public:
    static void* Malloc(unsigned int sizeInBytes);
    static void* MemSet(void* dest, int value, unsigned int sizeInBytes);
    static void* MemCpy(void* dest, const void* source, unsigned int sizeInBytes);
    static void Free(void* memoryBlock);
};
