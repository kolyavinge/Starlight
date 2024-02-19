#include <lib/Exceptions.h>
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

Vector3 VectorCalculator::GetMinVector(List<Vector3>& vectors)
{
    if (vectors.Count() == 0) throw ArgumentException();

    float minX = vectors[0].X;
    float minY = vectors[0].Y;
    float minZ = vectors[0].Z;

    for (int i = 1; i < vectors.Count(); i++)
    {
        Vector3& v = vectors[i];
        if (v.X < minX) minX = v.X;
        if (v.Y < minY) minY = v.Y;
        if (v.Z < minZ) minZ = v.Z;
    }

    return Vector3(minX, minY, minZ);
}

Vector3 VectorCalculator::GetMaxVector(List<Vector3>& vectors)
{
    if (vectors.Count() == 0) throw ArgumentException();

    float maxX = vectors[0].X;
    float maxY = vectors[0].Y;
    float maxZ = vectors[0].Z;

    for (int i = 1; i < vectors.Count(); i++)
    {
        Vector3& v = vectors[i];
        if (v.X > maxX) maxX = v.X;
        if (v.Y > maxY) maxY = v.Y;
        if (v.Z > maxZ) maxZ = v.Z;
    }

    return Vector3(maxX, maxY, maxZ);
}

void VectorCalculator::SwapXY(List<Vector3>& vectors)
{
    for (int i = 0; i < vectors.Count(); i++)
    {
        Vector3& v = vectors[i];
        float tmp = v.X;
        v.X = v.Y;
        v.Y = tmp;
    }
}

void VectorCalculator::SwapXZ(List<Vector3>& vectors)
{
    for (int i = 0; i < vectors.Count(); i++)
    {
        Vector3& v = vectors[i];
        float tmp = v.X;
        v.X = v.Z;
        v.Z = tmp;
    }
}

void VectorCalculator::SwapYZ(List<Vector3>& vectors)
{
    for (int i = 0; i < vectors.Count(); i++)
    {
        Vector3& v = vectors[i];
        float tmp = v.Y;
        v.Y = v.Z;
        v.Z = tmp;
    }
}

/* Проверка попадания точки point в одну четверть координатной плоскости
 * образованную векторами axis1 и axis2, выходящих из точки origin
 */
bool VectorCalculator::InQuadrant(Vector3& origin, Vector3 axis1, Vector3 axis2, Vector3 point)
{
    point.Sub(origin);
    if (point.IsZero()) return true;

    axis1.Sub(origin);
    axis2.Sub(origin);

    Vector3 checkDirection(point);
    checkDirection.VectorProduct(axis1);
    if (checkDirection.IsZero()) return true;
    checkDirection.Normalize();

    Vector3 areaDirection(axis2);
    areaDirection.VectorProduct(axis1);
    areaDirection.Normalize();

    Vector3 diff(areaDirection);
    diff.Sub(checkDirection);
    bool inArea = diff.GetLengthSquared() < 0.1f;

    return inArea;
}
