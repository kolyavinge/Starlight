#include "misc/SegmentIntersector.h"

bool SegmentIntersector::IsIntersected(
    float from1X, float from1Y,
    float to1X, float to1Y,
    float from2X, float from2Y,
    float to2X, float to2Y)
{
    float resultX, resultY;

    if (!IsLinesIntersected(from1X, from1Y, to1X, to1Y, from2X, from2Y, to2X, to2Y, &resultX, &resultY)) return false;

    return
        IsPointInSegment(from1X, from1Y, to1X, to1Y, resultX, resultY, 0.0001f) &&
        IsPointInSegment(from2X, from2Y, to2X, to2Y, resultX, resultY, 0.0001f);
}

bool SegmentIntersector::IsLinesIntersected(
    float from1X, float from1Y,
    float to1X, float to1Y,
    float from2X, float from2Y,
    float to2X, float to2Y,
    float* resultX, float* resultY)
{
    float a1 = from1Y - to1Y;
    float b1 = to1X - from1X;
    float c1 = from1X * to1Y - to1X * from1Y;

    float a2 = from2Y - to2Y;
    float b2 = to2X - from2X;
    float c2 = from2X * to2Y - to2X * from2Y;

    float denominator = a1 * b2 - a2 * b1;
    if (denominator == 0) return false;

    *resultX = (b1 * c2 - b2 * c1) / denominator;
    *resultY = (a2 * c1 - a1 * c2) / denominator;

    return true;
}

bool SegmentIntersector::IsPointInSegment(
    float fromX, float fromY,
    float toX, float toY,
    float pointX, float pointY,
    float delta)
{
    float minX, maxX, minY, maxY;

    if (fromX < toX)
    {
        minX = fromX;
        maxX = toX;
    }
    else
    {
        minX = toX;
        maxX = fromX;
    }

    if (fromY < toY)
    {
        minY = fromY;
        maxY = toY;
    }
    else
    {
        minY = toY;
        maxY = fromY;
    }

    return
        minX - delta <= pointX && pointX <= maxX + delta &&
        minY - delta <= pointY && pointY <= maxY + delta;
}
