#pragma once

#include <comdef.h>
#include <lib/Object.h>

class String : public Object
{
    static const int _initCapacity = 16;

    wchar_t* _symb;
    int _count;
    int _capacity;
    _bstr_t _tmp;

public:
    String();
    String(int capacity);
    String(const wchar_t* str);
    String(const char* str);
    String(const String& copy);
    ~String() override;

    bool Equals(Object& x) override;
    int GetHashCode() override;
    String& operator=(const String& copy);
    int GetLength();
    wchar_t& operator[](int index);
    String& Append(const wchar_t* appended);
    String& Append(const wchar_t appended);
    String& Append(String& appended);
    int IndexOf(const wchar_t ch);
    int LastIndexOf(const wchar_t ch);
    String Substring(int startIndex, int count);
    void Invert();
    void Clear();
    char* GetCharBuf();
    wchar_t* GetWCharBuf();

private:
    void Set(const String& copy);
    int GetLength(const wchar_t* str);
    int GetLength(const char* str);
    void ResizeIfNeeded(int newCount);
};
