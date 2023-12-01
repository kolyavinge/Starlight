#include "lib/Math.h"
#include "lib/Numeric.h"
#include "calc/VectorCalculator.h"

void VectorCalculator::GetNormalVector2d(
    float from1X, float from1Y,
    float to1X, float to1Y,
    float* resultX, float* resultY)
{
    if (Numeric::FloatEquals(from1X, to1X))
    {
        *resultX = 1.0f;
        *resultY = 0.0f;
    }
    else if (Numeric::FloatEquals(from1Y, to1Y))
    {
        *resultX = 0.0f;
        *resultY = 1.0f;
    }
    else
    {
        float sortedFromX, sortedFromY, sortedToX, sortedToY;
        if (from1X < to1X)
        {
            sortedFromX = from1X;
            sortedFromY = from1Y;
            sortedToX = to1X;
            sortedToY = to1Y;
        }
        else
        {
            sortedFromX = to1X;
            sortedFromY = to1Y;
            sortedToX = from1X;
            sortedToY = from1Y;
        }
        float alpha = Math::Abs(Math::ArcTan((sortedToY - sortedFromY) / (sortedToX - sortedFromX)));
        if (sortedToY < sortedFromY) alpha = -alpha;
        *resultX = Math::Cos(Math::PiHalf + alpha);
        *resultY = Math::Sin(Math::PiHalf + alpha);
    }
}
