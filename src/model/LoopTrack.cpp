#include <calc/Vector3d.h>
#include <anx/TrackBuilder.h>
#include <model/LoopTrack.h>

void LoopTrack::InternalInit()
{
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(10.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(40.0f);
    builder.TurnLeft(270.0f, 20.0f, Vector3d(0.0f, 0.0f, 1.0f));
    builder.InsideDirection.Z = 0.1f;
    builder.OutsideDirection.Z = 0.1f;

    builder.Move(80.0f);
    builder.TurnRight(200.0f, 20.0f, Vector3d(0.0f, 0.0f, 1.0f));
    builder.Move(10.0f);
    builder.TurnRight(45.0f, 20.0f, Vector3d(0.0f, 0.0f, 1.0f));

    builder.ConnectStartFinish();
}
