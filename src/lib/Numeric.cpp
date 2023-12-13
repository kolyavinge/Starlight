#include <lib/Math.h>
#include <lib/Numeric.h>

bool Numeric::FloatEquals(float a, float b)
{
    return Math::Abs(a - b) < 1E-7f;
}
