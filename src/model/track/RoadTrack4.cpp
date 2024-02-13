#include <lib/Math.h>
#include <calc/Vector3.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack4.h>

void RoadTrack4::InternalInit()
{
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(25.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(200.0f);
    builder.TurnLeft(270.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(200.0f);
    builder.TurnRight(80.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(45.0f, 120.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(200.0f);
    builder.TurnLeft(270.0f, 100.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(90.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(90.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(90.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnRight(180.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(90.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(90.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(200.0f);
    builder.TurnRight(180.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(200.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(200.0f);
    builder.TurnRight(80.0f, 40.0f, Vector3(0.0f, 0.0f, 1.0f));

    builder.ConnectStartFinish();

    float radians = 0.0f;
    float radiansStep = 8.0f * Math::Pi / (float)PointsCount;
    for (int i = 0; i < PointsCount; i++)
    {
        float z = 20.0f * Math::Sin(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z + 8.0f;
        radians += radiansStep;
    }
}
