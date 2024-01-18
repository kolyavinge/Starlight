#pragma once

#include <lib/Exceptions.h>
#include <lib/String.h>

class InvalidPathException : public Exception { };

class Path
{
public:
    static String GetDirectoryPath(String path);
    static String GetFileNameWithExtension(String path);
    static String GetFileNameWithoutExtension(String path);
    static String GetFileExtension(String path);
};
