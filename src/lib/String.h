#pragma once

#include <comdef.h>
#include <lib/Object.h>

class String : public Object
{
    wchar_t* _symb;
    int _count;
    int _capacity;
    _bstr_t _tmp;

public:
    String(const wchar_t* str);
    String(const String& copy);
    ~String();

    bool Equals(Object& x) override;
    int GetHashCode() override;
    String& operator=(const String& copy);
    int GetLength();
    wchar_t& operator[](int index);
    void Append(String& appended);
    char* GetCharBuf();
    wchar_t* GetWCharBuf();

private:
    void Set(const String& copy);
    int GetLength(const wchar_t* str);
};
