#include <model/RoadTrack1.h>
#include <anx/TrackBuilder.h>

void RoadTrack1::InternalInit()
{
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(15.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(0.0f, 0.0f, 3.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.Move(10.0f);
    builder.TurnLeft(90.0f, 10.0f);
    builder.Move(10.0f);
    builder.TurnRight(90.0f, 10.0f);
    builder.Move(10.0f);
    builder.TurnRight(90.0f, 10.0f);
    builder.Move(100.0f);
    builder.TurnRight(90.0f, 10.0f);
    builder.Move(100.0f);
    builder.TurnRight(90.0f, 10.0f);
    builder.Move(50.0f);
    builder.TurnRight(90.0f, 10.0f);
    builder.ConnectStartFinish();
}
