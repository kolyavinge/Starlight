#include <lib/Math.h>
#include <calc/Vector3d.h>
#include <model/RectBorder.h>

float RectBorder::GetAngleByX()
{
    Vector3d v(UpLeft);
    v.Sub(DownLeft);
    if (v.IsZero()) return 0.0f;
    v.Normalize();
    Vector3d straight(0.0f, 1.0f, 0.0f);
    float cosAlpha = v.DotProduct(straight);
    float alpha = Math::ArcCos(cosAlpha);
    if (v.X > 0.0f) alpha = -alpha;

    return alpha;
}

float RectBorder::GetAngleByY(Vector3d& normal)
{
    Vector3d v(normal);
    if (v.IsZero()) return 0.0f;
    v.Normalize();
    Vector3d straight(0.0f, 0.0f, 1.0f);
    float cosAlpha = v.DotProduct(straight);
    float alpha = Math::ArcCos(cosAlpha);
    if (v.X < 0.0f) alpha = -alpha;

    return alpha;
}

float RectBorder::GetAngleByZ()
{
    Vector3d v(UpLeft);
    v.Sub(DownLeft);
    if (v.IsZero()) return 0.0f;
    v.Normalize();
    Vector3d straight(0.0f, 1.0f, 0.0f);
    float cosAlpha = v.DotProduct(straight);
    float alpha = Math::ArcCos(cosAlpha);
    if (v.X > 0.0f) alpha = -alpha;

    return alpha;
}
