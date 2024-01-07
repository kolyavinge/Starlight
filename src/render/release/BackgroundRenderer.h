#pragma once

#include <lib/Object.h>
#include <calc/Sphere.h>

class BackgroundRenderer : public Object
{
    Sphere _sphere;

public:
    BackgroundRenderer();

    void Render();
};
