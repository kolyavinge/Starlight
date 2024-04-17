#include <lib/ArrayIndexGenerator.h>

ArrayIndexGenerator::ArrayIndexGenerator(int startIndex, int endIndex, int step)
{
    _endIndex = endIndex;
    _step = step;
    _current = startIndex - _step;
    _prev = _current;
}

bool ArrayIndexGenerator::MoveNext()
{
    if (_current >= _endIndex)
    {
        return false;
    }
    _prev = _current;
    _current += _step;
    if (_current > _endIndex)
    {
        _current = _endIndex;
    }

    return true;
}

int ArrayIndexGenerator::GetCurrentIndex()
{
    return _current;
}

int ArrayIndexGenerator::GetPrevIndex()
{
    return _prev;
}
