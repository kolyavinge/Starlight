#pragma once

#include <lib/Object.h>
#include <calc/Vector3d.h>

class RectBorder : public Object
{
public:
    Vector3d UpLeft;
    Vector3d UpRight;
    Vector3d DownLeft;
    Vector3d DownRight;
};
