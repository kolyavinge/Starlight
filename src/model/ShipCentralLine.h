#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class ShipCentralLine : public Object
{
public:
    Vector3 Front;
    Vector3 Rear;
    Vector3 NormalFront;
    Vector3 NormalRear;
    int TrackPointIndexFront;
    int TrackPointIndexRear;

    ShipCentralLine();

    void Init();
};
