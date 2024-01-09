#pragma once

#include <lib/Exceptions.h>

class FileNotFoundException : public Exception { };

class File
{
public:
    static bool Exists(const wchar_t* filePath);
    static void ErrorIfFileNotFound(const wchar_t* filePath);
};
