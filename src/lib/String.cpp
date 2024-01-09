#include <lib/HashCode.h>
#include <lib/String.h>

String::String(const wchar_t* str)
{
    for (const wchar_t* ch = str; *ch != '\0'; ch++)
    {
        _symb.Add(*ch);
    }
}

bool String::Equals(Object& x)
{
    String& str = (String&)x;

    if (_symb.Count() != str._symb.Count()) return false;

    for (int i = 0; i < _symb.Count(); i++)
    {
        if (_symb[i] != str._symb[i])
        {
            return false;
        }
    }

    return true;
}

int String::GetHashCode()
{
    HashCode hash;
    for (int i = 0; i < _symb.Count(); i++)
    {
        hash.Add(_symb[i]);
    }
    int result = hash.GetResult();

    return result;
}

int String::GetLength()
{
    return _symb.Count();
}

wchar_t& String::operator[](int index)
{
    return _symb[index];
}

void String::Concat(String& str)
{
    _symb.AddRange(str._symb);
}

wchar_t* String::GetCString()
{
    return _symb.GetItemsPointer();
}
