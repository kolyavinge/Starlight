#include <lib/Math.h>
#include <lib/Numeric.h>
#include <calc/VectorCalculator.h>

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

void VectorCalculator::GetNormalVector3d(Vector3& center, Vector3 right, Vector3 front, Vector3& result)
{
    right.Sub(center);
    front.Sub(center);
    right.VectorProduct(front);
    right.Normalize();
    result.Set(right);
}

bool VectorCalculator::IsSameDirection(Vector3& base, Vector3 v1, Vector3 v2)
{
    v1.VectorProduct(base);
    v2.VectorProduct(base);
    v1.Normalize();
    v2.Normalize();
    v1.Sub(v2);

    return v1.GetLengthSquared() < 0.1f;
}
