#include <lib/Exceptions.h>
#include <lib/Math.h>
#include <lib/NumericConverter.h>

String NumericConverter::IntToString(const int value)
{
    String result(8);
    IntToString(value, result);

    return result;
}

void NumericConverter::IntToString(const int value, String& result)
{
    IntToStringRec(Math::Abs(value), value < 0, result);
}

void NumericConverter::IntToStringRec(const int remainAbs, bool isNegative, String& result)
{
    if (remainAbs > 9)
    {
        int lastDigit = remainAbs % 10;
        IntToStringRec(remainAbs / 10, isNegative, result);
        result.Append(GetChar(lastDigit));
    }
    else
    {
        if (isNegative)
        {
            result.Append(L'-');
        }
        result.Append(GetChar(remainAbs));
    }
}

wchar_t NumericConverter::GetChar(int digit)
{
    switch (digit)
    {
        case 0: return L'0';
        case 1: return L'1';
        case 2: return L'2';
        case 3: return L'3';
        case 4: return L'4';
        case 5: return L'5';
        case 6: return L'6';
        case 7: return L'7';
        case 8: return L'8';
        case 9: return L'9';
        default: throw ArgumentException();
    }
}
