#pragma once

#include <lib/List.h>
#include <lib/String.h>

class Directory
{
public:
    static void GetFiles(String directory, List<String>& files);
};
