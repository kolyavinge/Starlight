#include <lib/Memory.h>
#include <lib/HashCode.h>
#include <lib/String.h>

String::String(const wchar_t* str)
{
    _count = GetLength(str);
    _capacity = 2 * _count;
    _symb = Memory::Alloc<wchar_t>(_capacity);
    Memory::Zero<wchar_t>(_symb, _capacity);
    Memory::Copy<wchar_t>(str, _symb, _count);
}

String::String(const String& copy)
{
    _symb = nullptr;
    Set(copy);
}

String::~String()
{
    Memory::Release(_symb);
    _symb = nullptr;
}

bool String::Equals(Object& x)
{
    String& str = (String&)x;

    if (_count != str._count) return false;

    for (int i = 0; i < _count; i++)
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
    for (int i = 0; i < _count; i++)
    {
        hash.Add(_symb[i]);
    }
    int result = hash.GetResult();

    return result;
}

String& String::operator=(const String& copy)
{
    Set(copy);
    return *this;
}

int String::GetLength()
{
    return _count;
}

wchar_t& String::operator[](int index)
{
    return _symb[index];
}

void String::Append(String& appended)
{
    int newCount = _count + appended._count + 1; // +1 - zero terminated
    if (newCount > _capacity)
    {
        _capacity = 2 * newCount;
        Memory::Resize<wchar_t>(_symb, _count, _capacity);
        Memory::Zero<wchar_t>(&_symb[_count], (_capacity - _count));
    }
    Memory::Copy<wchar_t>(appended._symb, &_symb[_count], appended._count);
    _count += appended._count;
}

char* String::GetCharBuf()
{
    _tmp = _symb; // convert wchar_t -> char
    return _tmp;
}

wchar_t* String::GetWCharBuf()
{
    return _symb;
}

void String::Set(const String& copy)
{
    _count = copy._count;
    _capacity = copy._capacity;
    if (_symb != nullptr)
    {
        Memory::Release(_symb);
    }
    _symb = Memory::Alloc<wchar_t>(_capacity);
    Memory::Copy<wchar_t>(copy._symb, _symb, _capacity);
}

int String::GetLength(const wchar_t* str)
{
    int len = 0;
    for (int i = 0; str[i] != L'\0'; i++) len++;
    return len;
}
