#include <lib/Math.h>
#include <lib/Numeric.h>

bool Numeric::FloatEquals(float a, float b, float eps)
{
    return Math::Abs(a - b) < eps;
}
