#include <lib/Math.h>
#include <calc/Vector3.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack3.h>

void RoadTrack3::InternalInit()
{
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointInfos, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(20.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(300.0f);
    builder.TurnLeft(180.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(50.0f);
    builder.TurnRight(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(180.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(400.0f);
    builder.TurnRight(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnRight(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(300.0f);
    builder.TurnLeft(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(180.0f, 70.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(60.0f);
    builder.TurnLeft(180.0f, 40.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(50.0f);
    builder.TurnLeft(180.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(50.0f);
    builder.TurnRight(180.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(180.0f);
    builder.TurnLeft(90.0f, 60.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(200.0f);
    builder.TurnRight(180.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(150.0f);
    builder.TurnLeft(90.0f, 40.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(90.0f, 40.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(122.0f);
    builder.TurnLeft(90.0f, 40.0f, Vector3(0.0f, 0.0f, 1.0f));

    builder.ConnectStartFinish();

    float radians = 0.0f;
    float radiansStep = 6.0f * Math::PiDouble / (float)PointsCount;
    for (int i = 0; i < PointsCount; i++)
    {
        float z = 30.0f * Math::Sin(radians);
        InsidePoints[i].Z = z;
        OutsidePoints[i].Z = z + 10.0f;
        radians += radiansStep;
    }
}
