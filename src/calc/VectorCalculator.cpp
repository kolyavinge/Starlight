#include "lib/Math.h"
#include "lib/Numeric.h"
#include "calc/VectorCalculator.h"

void VectorCalculator::GetNormalVector2d(
    float fromX, float fromY,
    float toX, float toY,
    float* resultX, float* resultY)
{
    if (Numeric::FloatEquals(fromX, toX))
    {
        *resultX = 1.0f;
        *resultY = 0.0f;
    }
    else if (Numeric::FloatEquals(fromY, toY))
    {
        *resultX = 0.0f;
        *resultY = 1.0f;
    }
    else
    {
        float sortedFromX, sortedFromY, sortedToX, sortedToY;
        if (fromX < toX)
        {
            sortedFromX = fromX;
            sortedFromY = fromY;
            sortedToX = toX;
            sortedToY = toY;
        }
        else
        {
            sortedFromX = toX;
            sortedFromY = toY;
            sortedToX = fromX;
            sortedToY = fromY;
        }
        float alpha = Math::Abs(Math::ArcTan((sortedToY - sortedFromY) / (sortedToX - sortedFromX)));
        if (sortedToY < sortedFromY) alpha = -alpha;
        *resultX = Math::Cos(Math::PiHalf + alpha);
        *resultY = Math::Sin(Math::PiHalf + alpha);
    }
}

void VectorCalculator::GetNormalVector3d(Vector3d& v1, Vector3d& v2, Vector3d& v3, Vector3d& result)
{
    Vector3d v21(v2);
    v21.Sub(v1);

    Vector3d v31(v3);
    v31.Sub(v1);

    v21.VectorProduct(v31);
    v21.Normalize();

    result.Set(v21);
}
