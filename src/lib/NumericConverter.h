#pragma once

#include <lib/String.h>

class NumericConverter
{
public:
    static String IntToString(const int value);

private:
    static wchar_t GetChar(int digit);
};
