#include <lib/Assert.h>

void Assert::Fail()
{
    throw AssertException();
}

void Assert::True(bool condition)
{
    if (!condition)
    {
        throw AssertException();
    }
}

void Assert::False(bool condition)
{
    if (condition)
    {
        throw AssertException();
    }
}
