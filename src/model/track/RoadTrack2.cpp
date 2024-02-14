#include <lib/Math.h>
#include <calc/Vector3.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack2.h>

void RoadTrack2::InternalInit()
{
    StartFinishLineIndex = 200;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(20.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(300.0f);
    builder.TurnRight(140.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(160.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(150.0f);
    builder.TurnLeft(180.0f, 170.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(80.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(200.0f, 80.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnLeft(120.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(100.0f, 25.0f, Vector3(0.0f, 0.0f, 1.0f));

    builder.ConnectStartFinish();

    float radians = 0.5f;
    float radiansStep = 8.0f * Math::Pi / (float)PointsCount;
    for (int i = 0; i < PointsCount; i++)
    {
        float z = 30.0f * Math::Sin(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z + 10.0f;
        radians += radiansStep;
    }
}
