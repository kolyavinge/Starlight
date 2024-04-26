#include <iostream>
#include <lib/Debug.h>

void Debug::Info(int value)
{
    std::cout << value;
    std::cout << "\r\n";
}

void Debug::Info(wchar_t* str)
{
    Info(String(str));
}

void Debug::Info(String str)
{
    std::cout << str.GetCharBuf();
    std::cout << "\r\n";
}
