#pragma once

#include <lib/Object.h>
#include <lib/List.h>

class String : public Object
{
    List<wchar_t> _symb;

public:
    String(const wchar_t* str);

    bool Equals(Object& x) override;
    int GetHashCode() override;
    int GetLength();
    wchar_t& operator[](int index);
    void Concat(String& str);
    wchar_t* GetCString();
};
