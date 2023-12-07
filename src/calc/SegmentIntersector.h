#pragma once

#include "lib/Object.h"
#include "calc/LineIntersector.h"

class SegmentIntersector : public Object
{
public:
    bool AreSegmentsIntersected(
        float from1X, float from1Y,
        float to1X, float to1Y,
        float from2X, float from2Y,
        float to2X, float to2Y);

    bool IsPointIntersected(
        float fromX, float fromY,
        float toX, float toY,
        float pointX, float pointY,
        float pointRadius);

private:
    bool IsPointInSegment(
        float fromX, float fromY,
        float toX, float toY,
        float pointX, float pointY,
        float delta);

private:
    LineIntersector _lineIntersector;
};
