#include <calc/Vector3.h>
#include <anx/TrackBuilder.h>
#include <model/track/RoadTrack1.h>

void RoadTrack1::InternalInit()
{
    StartFinishLineIndex = 10;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);
    //StartFinishLineIndex = 1100;
    //StraightDirection.Set(-1.0f, -1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(8.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(0.0f, 0.0f, 3.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(100.0f);
    builder.TurnRight(90.0f, 100.0f, Vector3(-0.2f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(45.0f, 50.0f, Vector3(-0.1f, 0.0f, 1.0f));
    builder.Move(20.0f);
    builder.TurnRight(45.0f, 20.0f, Vector3(0.1f, 0.0f, 1.0f));
    builder.Move(20.0f);
    builder.TurnLeft(45.0f, 50.0f, Vector3(-0.1f, 0.0f, 1.0f));
    builder.Move(20.0f);
    builder.TurnRight(45.0f, 20.0f, Vector3(0.1f, 0.0f, 1.0f));
    builder.Move(20.0f);
    builder.TurnRight(170.0f, 5.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.InsideDirection.Z = -0.5f;
    builder.OutsideDirection.Z = -0.5f;
    builder.Move(100.0f);
    builder.TurnLeft(100.0f, 5.0f, Vector3(0.25f, 0.0f, 1.0f));
    builder.Move(10.0f);
    builder.TurnRight(90.0f, 10.0f, Vector3(-0.25f, 0.0f, 1.0f));
    builder.TurnRight(90.0f, 40.0f, Vector3(-0.5f, 0.0f, 1.0f));
    builder.InsideDirection.Z = -0.5f;
    builder.OutsideDirection.Z = -0.5f;
    builder.Move(20.0f);
    builder.TurnLeft(120.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.TurnRight(45.0f, 100.0f, Vector3(0.2f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnLeft(120.0f, 50.0f, Vector3(0.0f, 0.0f, 1.0f));
    builder.Move(100.0f);
    builder.TurnRight(90.0f, 100.0f, Vector3(0.2f, 0.0f, 1.0f));
    builder.TurnRight(140.0f, 10.0f, Vector3(0.2f, 0.0f, 1.0f));

    builder.ConnectStartFinish();
}
