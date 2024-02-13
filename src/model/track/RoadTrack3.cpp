#include <lib/Math.h>
#include <model/track/RoadTrack3.h>

void RoadTrack3::InternalInit()
{
    PointsCount = 400;
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    const float insideRadius = 20.0f;
    const float outsideRadius = 60.0f;

    float step = 2.0f * Math::Pi / (float)PointsCount;
    float radians = 0.0f;
    float x, y, sin, cos;

    for (int i = 0; i < PointsCount; i++)
    {
        sin = Math::Sin(radians);
        cos = Math::Cos(radians);

        x = insideRadius * cos;
        y = insideRadius * sin;
        InsidePoints[i].Set(x, y, 0.0f);

        x = outsideRadius * cos;
        y = outsideRadius * sin;
        OutsidePoints[i].Set(x, y, 2.0f);

        radians += step;
    }
}
