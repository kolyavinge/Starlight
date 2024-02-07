#include <lib/Exceptions.h>
#include <lib/Math.h>
#include <lib/NumericConverter.h>

String NumericConverter::IntToString(const int value)
{
    String res(8);
    int remain = Math::Abs(value);
    while (remain > 9)
    {
        int lastDigit = remain % 10;
        res.Append(GetChar(lastDigit));
        remain /= 10;
    }
    res.Append(GetChar(remain));
    if (value < 0)
    {
        res.Append(L'-');
    }
    res.Invert();

    return res;
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
