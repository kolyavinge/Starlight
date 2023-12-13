#include <calc/LineIntersector.h>

bool LineIntersector::GetIntersectPoint(
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
