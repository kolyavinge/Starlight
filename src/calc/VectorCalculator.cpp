#include <lib/Exceptions.h>
#include <calc/VectorCalculator.h>

void VectorCalculator::GetNormalVector(Vector3& origin, Vector3 right, Vector3 front, Vector3& result)
{
    right.Sub(origin);
    front.Sub(origin);
    right.VectorProduct(front);
    right.Normalize();
    result.Set(right);
}

bool VectorCalculator::IsSameDirection(Vector3& origin, Vector3 v1, Vector3 v2)
{
    v1.VectorProduct(origin);
    v2.VectorProduct(origin);
    v1.Normalize();
    v2.Normalize();
    v1.Sub(v2);

    return v1.GetLengthSquared() < 0.1f;
}

Vector3 VectorCalculator::GetMinVector(IArray<Vector3>& vectors)
{
    if (vectors.GetCount() == 0) throw ArgumentException();

    float minX = vectors[0].X;
    float minY = vectors[0].Y;
    float minZ = vectors[0].Z;

    for (int i = 1; i < vectors.GetCount(); i++)
    {
        Vector3& v = vectors[i];
        if (v.X < minX) minX = v.X;
        if (v.Y < minY) minY = v.Y;
        if (v.Z < minZ) minZ = v.Z;
    }

    return Vector3(minX, minY, minZ);
}

Vector3 VectorCalculator::GetMaxVector(IArray<Vector3>& vectors)
{
    if (vectors.GetCount() == 0) throw ArgumentException();

    float maxX = vectors[0].X;
    float maxY = vectors[0].Y;
    float maxZ = vectors[0].Z;

    for (int i = 1; i < vectors.GetCount(); i++)
    {
        Vector3& v = vectors[i];
        if (v.X > maxX) maxX = v.X;
        if (v.Y > maxY) maxY = v.Y;
        if (v.Z > maxZ) maxZ = v.Z;
    }

    return Vector3(maxX, maxY, maxZ);
}

void VectorCalculator::SwapXY(IArray<Vector3>& vectors)
{
    for (int i = 0; i < vectors.GetCount(); i++)
    {
        Vector3& v = vectors[i];
        float tmp = v.X;
        v.X = v.Y;
        v.Y = tmp;
    }
}

void VectorCalculator::SwapXZ(IArray<Vector3>& vectors)
{
    for (int i = 0; i < vectors.GetCount(); i++)
    {
        Vector3& v = vectors[i];
        float tmp = v.X;
        v.X = v.Z;
        v.Z = tmp;
    }
}

void VectorCalculator::SwapYZ(IArray<Vector3>& vectors)
{
    for (int i = 0; i < vectors.GetCount(); i++)
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
bool VectorCalculator::IsPointInQuadrant(Vector3& origin, Vector3 axis1, Vector3 axis2, Vector3 point)
{
    point.Sub(origin);
    if (point.IsZero()) return true;

    axis1.Sub(origin);
    axis2.Sub(origin);

    Vector3 checkDirection(point);
    checkDirection.VectorProduct(axis1);

    Vector3 areaDirection(axis2);
    areaDirection.VectorProduct(axis1);

    float dotProduct = areaDirection.DotProduct(checkDirection);
    bool inArea = dotProduct >= 0.0f;

    return inArea;
}
