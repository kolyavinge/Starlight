#pragma once

#include "lib/Object.h"
#include "lib/Array.h"
#include "calc/Vector3d.h"

#define TrackMaxPoints 1000

class TrackPoints : public Array<Vector3d, TrackMaxPoints> { };

class Track : public Object
{
public:
    int PointsCount;
    TrackPoints OutsidePoints;
    TrackPoints InsidePoints;
    Vector3d StraightDirection;
    int StartFinishLineIndex;

    Track();

    virtual void Init() = 0;
};
