#pragma once

#include <lib/Exceptions.h>

class FileNotFoundException : public Exception { };
class ReadFileException : public Exception { };

class File
{
public:
    static bool Exists(const wchar_t* filePath);
    static void ErrorIfFileNotFound(const wchar_t* filePath);
    static int GetFileSizeBytes(const wchar_t* filePath);
    static int ReadAllBytes(const wchar_t* filePath, int bufferSize, void* buffer);
};
