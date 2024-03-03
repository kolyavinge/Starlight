#include <core/cm/TrackCollisionResult.h>

TrackCollisionResult::TrackCollisionResult()
{
    Init();
}

void TrackCollisionResult::Init()
{
    FromTrackPoint.Set(0.0f, 0.0f, 0.0f);
    ToTrackPoint.Set(0.0f, 0.0f, 0.0f);
    OppositeTrackPoint.Set(0.0f, 0.0f, 0.0f);
    FromIndex = 0;
    ToIndex = 0;
}
