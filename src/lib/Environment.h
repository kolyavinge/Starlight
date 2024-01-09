#pragma once

#include <lib/String.h>

class Environment
{
public:
    static String GetCurrentDirectoryPath();
    static String GetExecutableFilePath();
    static String GetExecutableDirectoryPath();
};
