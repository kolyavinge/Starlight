#include <calc/Vector3d.h>
#include <anx/TrackBuilder.h>
#include <model/track/WheelTrack.h>

void WheelTrack::InternalInit()
{
    StartFinishLineIndex = 0;
    StraightDirection.Set(0.0f, 1.0f, 0.0f);

    TrackBuilder builder(InsidePoints, OutsidePoints, PointsCount);

    builder.InitInsidePosition(0.0f, 0.0f, 0.0f);
    builder.InitOutsidePosition(10.0f, 0.0f, 0.0f);

    builder.InsideDirection.Set(0.0f, 1.0f, 0.0f);
    builder.OutsideDirection.Set(0.0f, 1.0f, 0.0f);

    builder.TurnLeft(360.0f, 50.0f, Vector3d(0.25f, 0.0f, 1.0f));
}
