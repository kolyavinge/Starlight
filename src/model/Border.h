#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>

class Border : public Object
{
public:
    Vector3 UpLeft;
    Vector3 UpRight;
    Vector3 DownLeft;
    Vector3 DownRight;

    void GetAngleAndPivot(float& radians, Vector3& pivot);
};
