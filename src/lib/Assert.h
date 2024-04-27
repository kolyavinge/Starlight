#pragma once

#include <lib/Exceptions.h>

class AssertException : public Exception {};

class Assert
{
public:
    static void Fail();
    static void True(bool condition);
    static void False(bool condition);
    static void Between(int value, int from, int to);
};
