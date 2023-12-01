#pragma once

#include "lib/Object.h"
#include "lib/Array.h"
#include "calc/Vector3d.h"

#define TrackMaxPoints 1000

class Track : public Object
{
public:
    int PointsCount;
    Array<Vector3d, TrackMaxPoints> OutsidePoints;
    Array<Vector3d, TrackMaxPoints> InsidePoints;
    Vector3d StraightDirection;
    int StartFinishLineIndex;

    Track();

    virtual void Init() = 0;
};
