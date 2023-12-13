#include <malloc.h>
#include <cstring>
#include <lib/Exceptions.h>
#include <lib/Memory.h>

void* Memory::Alloc(unsigned int countBytes)
{
    void* result = malloc(countBytes);
    if (result == nullptr) throw MemoryAllocationException();

    return result;
}

void* Memory::Zero(void* source, unsigned int countBytes)
{
    return std::memset(source, 0, countBytes);
}

void Memory::Copy(void* source, void* dest, unsigned int countBytes)
{
    std::memcpy(dest, source, countBytes);
}

void Memory::Release(void* source)
{
    free(source);
}

void Memory::Resize(void*& source, unsigned int countBytes)
{
    void* newSource = Alloc(countBytes);
    Copy(source, newSource, countBytes);
    Release(source);
    source = newSource;
}
