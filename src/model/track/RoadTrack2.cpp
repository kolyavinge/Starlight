#include <lib/Math.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack2.h>

void RoadTrack2::InternalInit()
{
    TrackBuilder builder(InsidePoints, OutsidePoints, PointInfos, PointsCount);

    builder.InitInsidePosition(20.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(0.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.TurnRight(180.0f, 150.0f);
    builder.TurnRight(90.0f, 100.0f);
    builder.TurnLeft(90.0f, 100.0f);
    builder.Move(200.0f);
    builder.TurnRight(200.0f, 200.0f);
    builder.Move(50.0f);
    builder.TurnRight(90.0f, 60.0f);
    builder.Move(60.0f);
    builder.TurnLeft(100.0f, 90.0f);

    int pointCountBeforeFinishLine = PointsCount;
    builder.ConnectStartFinish();

    StartFinishLineIndex = pointCountBeforeFinishLine + 500;

    for (int i = 0; i < PointsCount; i++)
    {
        InsidePoints[i].Z = 20.0f;
        OutsidePoints[i].Z = 20.0f;
    }

    float radians = 0.0f;
    float radiansStep = Math::PiDouble / (float)pointCountBeforeFinishLine;
    for (int i = 0; i < pointCountBeforeFinishLine; i++)
    {
        float z = 20.0f * Math::Cos(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z;
        radians += radiansStep;
    }
}
