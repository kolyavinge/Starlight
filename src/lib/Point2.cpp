#include <lib/Point2.h>

Point2::Point2()
{
    Set(0.0f, 0.0f);
}

Point2::Point2(float x, float y)
{
    Set(x, y);
}

void Point2::Set(float x, float y)
{
    X = x;
    Y = y;
}
