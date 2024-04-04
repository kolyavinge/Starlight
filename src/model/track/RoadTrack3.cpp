#include <lib/Math.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack3.h>

void RoadTrack3::InternalInit()
{
    TrackBuilder builder(InsidePoints, OutsidePoints, PointInfos, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(20.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.TurnLeft(280.0f, 150.0f);
    builder.Move(150.0f);
    builder.TurnRight(180.0f, 250.0f);
    builder.TurnLeft(180.0f, 80.0f);
    builder.TurnLeft(90.0f, 60.0f);

    int pointCountBeforeFinishLine = PointsCount;
    builder.ConnectStartFinish();

    StartFinishLineIndex = pointCountBeforeFinishLine + 2000;

    for (int i = 0; i < PointsCount; i++)
    {
        InsidePoints[i].Z = 20.0f;
        OutsidePoints[i].Z = 20.0f;
    }

    float radians = 0.0f;
    float radiansStep = 2.0f * Math::PiDouble / (float)pointCountBeforeFinishLine;
    for (int i = 0; i < pointCountBeforeFinishLine; i++)
    {
        float z = 20.0f * Math::Cos(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z;
        radians += radiansStep;
    }
}
