#include "lib/HashCode.h"

HashCode::HashCode()
{
    _result = 1430287;
}

void HashCode::Add(int value)
{
    _result = _result * 7302013 ^ value;
}

void HashCode::Add(float value)
{
    int bytes = *(int*)&value;
    Add(bytes);
}

void HashCode::Add(double value)
{
    int bytes = *(int*)&value;
    Add(bytes);
}

int HashCode::GetResult()
{
    return _result;
}
