#include "lib/Hash.h"

Hash::Hash()
{
    _result = 1430287;
}

void Hash::Add(int value)
{
    _result = _result * 7302013 ^ value;
}

void Hash::Add(float value)
{
    int bytes = *(int*)&value;
    Add(bytes);
}

void Hash::Add(double value)
{
    int bytes = *(int*)&value;
    Add(bytes);
}

int Hash::GetResult()
{
    return _result;
}
