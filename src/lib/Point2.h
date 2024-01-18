#pragma once

#include <lib/Object.h>

class Point2 : public Object
{
public:
    float X;
    float Y;

    Point2();
    Point2(float x, float y);

    void Set(float x, float y);
};
