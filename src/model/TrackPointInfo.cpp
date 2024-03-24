#include <model/TrackPointInfo.h>

TrackPointInfo::TrackPointInfo()
{
    Kind = TrackPointKind::Straight;
    RemainingDistance = 0.0f;
    Radius = 0.0f;
}
