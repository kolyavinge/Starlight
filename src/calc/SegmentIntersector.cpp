#include <lib/Math.h>
#include <calc/SegmentIntersector.h>

bool SegmentIntersector::AreSegmentsIntersected(
    float from1X, float from1Y,
    float to1X, float to1Y,
    float from2X, float from2Y,
    float to2X, float to2Y)
{
    float resultX, resultY;

    if (!_lineIntersector.GetIntersectPoint(from1X, from1Y, to1X, to1Y, from2X, from2Y, to2X, to2Y, &resultX, &resultY)) return false;

    return
        IsPointInSegment(from1X, from1Y, to1X, to1Y, resultX, resultY, 1e-5f) &&
        IsPointInSegment(from2X, from2Y, to2X, to2Y, resultX, resultY, 1e-5f);
}

bool SegmentIntersector::IsPointIntersected(
    float fromX, float fromY,
    float toX, float toY,
    float pointX, float pointY,
    float pointRadius)
{
    const float delta = 1e-5f;

    // двигаем точку в начало координат
    float lineFromX = fromX - pointX;
    float lineFromY = fromY - pointY;
    float lineToX = toX - pointX;
    float lineToY = toY - pointY;

    // уравнение прямой
    float a = lineFromY - lineToY;
    float b = lineToX - lineFromX;
    float c = lineFromX * lineToY - lineToX * lineFromY;

    float m = a * a + b * b;
    float c2 = c * c;
    if (c2 > pointRadius * m + delta) return false;

    float x0 = -a * c / m;
    float y0 = -b * c / m;
    float d = pointRadius - c2 / m;
    float mult = Math::Sqrt(d / m);
    float ax = x0 + b * mult;
    float ay = y0 - a * mult;

    return IsPointInSegment(fromX, fromY, toX, toY, ax + pointX, ay + pointY, delta);
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
