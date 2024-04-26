#pragma once

#include <lib/String.h>

class Debug
{
public:
    static void Info(int value);
    static void Info(wchar_t* str);
    static void Info(String str);
};
