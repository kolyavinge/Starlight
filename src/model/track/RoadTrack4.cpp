#include <lib/Math.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack4.h>

void RoadTrack4::InternalInit()
{
    StartFinishLineIndex = 0;

    TrackBuilder builder(InsidePoints, OutsidePoints, PointInfos, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(20.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(200.0f);
    builder.TurnLeft(270.0f, 80.0f);
    builder.Move(200.0f);
    builder.TurnRight(80.0f, 80.0f);
    builder.TurnLeft(45.0f, 120.0f);
    builder.Move(200.0f);
    builder.TurnLeft(270.0f, 100.0f);
    builder.TurnLeft(90.0f, 50.0f);
    builder.TurnRight(90.0f, 50.0f);
    builder.TurnLeft(90.0f, 50.0f);
    builder.Move(100.0f);
    builder.TurnRight(180.0f, 50.0f);
    builder.TurnLeft(90.0f, 50.0f);
    builder.TurnRight(90.0f, 50.0f);
    builder.Move(200.0f);
    builder.TurnRight(180.0f, 50.0f);
    builder.TurnLeft(200.0f, 50.0f);
    builder.Move(200.0f);
    builder.TurnRight(70.0f, 40.0f);

    int pointCountBeforeFinishLine = PointsCount;
    builder.ConnectStartFinish();

    for (int i = 0; i < PointsCount; i++)
    {
        InsidePoints[i].Z = 40.0f;
        OutsidePoints[i].Z = 40.0f;
    }

    float radians = 0.0f;
    float radiansStep = Math::PiDouble / (float)pointCountBeforeFinishLine;
    for (int i = 0; i < pointCountBeforeFinishLine; i++)
    {
        float z = 40.0f * Math::Cos(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z;
        radians += radiansStep;
    }
}
