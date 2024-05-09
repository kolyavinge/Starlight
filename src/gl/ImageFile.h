#pragma once

#include <lib/Object.h>

class ImageFile : public Object
{
public:
    static void GetSize(const wchar_t* fileName, int* width, int* height);
};
