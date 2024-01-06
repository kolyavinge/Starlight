#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class TrackCollisionResult : public Object
{
public:
    Vector3 FromTrackPoint;
    Vector3 ToTrackPoint;
    Vector3 OppositeTrackPoint;
    int FromIndex;
    int ToIndex;

    TrackCollisionResult();

    void Init();
};
