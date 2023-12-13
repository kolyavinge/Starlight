#pragma once

#include <lib/Object.h>

class LineIntersector : public Object
{
public:
    bool GetIntersectPoint(
        float from1X, float from1Y,
        float to1X, float to1Y,
        float from2X, float from2Y,
        float to2X, float to2Y,
        float* resultX, float* resultY);
};
