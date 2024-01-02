#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class TrackCollisionResult : public Object
{
public:
    Vector3d FromTrackPoint;
    Vector3d ToTrackPoint;
    Vector3d OppositeTrackPoint;
    int FromIndex;
    int ToIndex;

    TrackCollisionResult();

    void Init();
};
