#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/Math.h>
#include <calc/Vector3.h>

#define TrackEdgeMaxPoints 16

class TrackEdge : public Object
{
public:
    inline static const float RadiansStep = Math::PiDouble / (float)TrackEdgeMaxPoints;

    Array<Vector3, TrackEdgeMaxPoints> Points;
};
