#pragma once

#include <lib/Object.h>
#include <calc/Sphere.h>

class DebugBackgroundRenderer : public Object
{
    Sphere _sphere;

public:
    DebugBackgroundRenderer();

    void Render();
};
