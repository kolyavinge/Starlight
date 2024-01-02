#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class ShipCentralLine : public Object
{
public:
    Vector3d Front;
    Vector3d Rear;
    Vector3d NormalFront;
    Vector3d NormalRear;
    int TrackPointIndexFront = 0;
    int TrackPointIndexRear = 0;
};
