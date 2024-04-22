#pragma once

#include <lib/Object.h>

class Face : public Object
{
public:
    unsigned int i0;
    unsigned int i1;
    unsigned int i2;

    Face();
    Face(unsigned int i0, unsigned int i1, unsigned int i2);
};
