#pragma once

#include <lib/String.h>

class NumericConverter
{
public:
    static String IntToString(const int value);
    static void IntToString(const int value, String& result);

private:
    static void IntToStringRec(const int remainAbs, bool isNegative, String& result);
    static wchar_t GetChar(int digit);
};
