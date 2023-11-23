#include <cmath>
#include "lib/Math.h"

const float Math::Pi = 3.14159265359f;

float Math::Abs(float x)
{
    return fabs(x);
}

float Math::Sqrt(float x)
{
    return sqrtf(x);
}

float Math::Sin(float x)
{
    return sinf(x);
}

float Math::Cos(float x)
{
    return cosf(x);
}

float Math::Tan(float x)
{
    return tanf(x);
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
