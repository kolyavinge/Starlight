#pragma once

class Memory
{
public:
    static void* Alloc(unsigned int countBytes);
    static void* Zero(void* source, unsigned int countBytes);
    static void Copy(const void* source, void* dest, unsigned  int countBytes);
    static void Release(void* source);
    static void Resize(void*& source, unsigned  int countBytes);
};
