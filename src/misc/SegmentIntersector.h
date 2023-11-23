#pragma once

#include "lib/Object.h"

class SegmentIntersector : public Object
{
public:
    bool IsIntersected(
        float from1X, float from1Y,
        float to1X, float to1Y,
        float from2X, float from2Y,
        float to2X, float to2Y);

private:
    bool IsLinesIntersected(
        float from1X, float from1Y,
        float to1X, float to1Y,
        float from2X, float from2Y,
        float to2X, float to2Y,
        float* resultX, float* resultY);

    bool IsPointInSegment(
        float fromX, float fromY,
        float toX, float toY,
        float pointX, float pointY,
        float delta);
};
