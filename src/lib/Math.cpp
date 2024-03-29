#include <cmath>
#include <lib/Exceptions.h>
#include <lib/Math.h>

float Math::Min(float a, float b)
{
    return a < b ? a : b;
}

float Math::Max(float a, float b)
{
    return a > b ? a : b;
}

int Math::Abs(int x)
{
    return x > 0.0f ? x : -x;
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
    if (x > 1.0f || x < -1.0f) throw ArgumentException();
    return asinf(x);
}

float Math::ArcCos(float x)
{
    if (x > 1.0f || x < -1.0f) throw ArgumentException();
    return acosf(x);
}

float Math::ArcTan(float x)
{
    return atanf(x);
}

float Math::Power(float x, float pow)
{
    return powf(x, pow);
}

float Math::LogE(float x)
{
    return logf(x);
}

float Math::Round(float x, float precision)
{
    return std::round(x / precision) * precision;
}
