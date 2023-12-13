#include <cmath>
#include <lib/Math.h>

const float Math::Pi = 3.14159265359f;
const float Math::PiHalf = Pi / 2.0f;
const float Math::PiDouble = 2.0f * Pi;

float Math::Min(float a, float b)
{
    return a < b ? a : b;
}

float Math::Max(float a, float b)
{
    return a > b ? a : b;
}

float Math::Abs(float x)
{
    return x > 0.0f ? x : -x;
}

float Math::Sqrt(float x)
{
    return sqrtf(x);
}

float Math::Sin(float radians)
{
    return sinf(radians);
}

float Math::Cos(float radians)
{
    return cosf(radians);
}

float Math::Tan(float radians)
{
    return tanf(radians);
}

float Math::ArcSin(float x)
{
    return asinf(x);
}

float Math::ArcCos(float x)
{
    return acosf(x);
}

float Math::ArcTan(float x)
{
    return atanf(x);
}

float Math::LogE(float x)
{
    return logf(x);
}
