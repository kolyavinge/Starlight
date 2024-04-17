#pragma once

#include <lib/Object.h>

class ArrayIndexGenerator : public Object
{
    int _endIndex;
    int _step;
    int _current;
    int _prev;

public:
    ArrayIndexGenerator(int startIndex, int endIndex, int step);

    bool MoveNext();
    int GetCurrentIndex();
    int GetPrevIndex();
};
