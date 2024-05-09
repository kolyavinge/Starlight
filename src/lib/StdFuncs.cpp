#include <malloc.h>
#include <cstring>
#include <lib/StdFuncs.h>

void* StdFuncs::Malloc(unsigned int sizeInBytes)
{
    return malloc(sizeInBytes);
}

void* StdFuncs::MemSet(void* dest, int value, unsigned int sizeInBytes)
{
    return std::memset(dest, value, sizeInBytes);
}

void* StdFuncs::MemCpy(void* dest, const void* source, unsigned int sizeInBytes)
{
    return std::memcpy(dest, source, sizeInBytes);
}

void StdFuncs::Free(void* memoryBlock)
{
    free(memoryBlock);
}
