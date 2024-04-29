#include <lib/Math.h>
#include <lib/Numeric.h>

bool Numeric::FloatEquals(float a, float b, float eps)
{
    return Math::Abs(a - b) < eps;
}

bool Numeric::Between(int x, int left, int right)
{
    return left <= x && x <= right;
}

bool Numeric::Between(float x, float left, float right)
{
    return left <= x && x <= right;
}
