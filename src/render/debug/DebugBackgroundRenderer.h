#pragma once

#include <lib/Object.h>
#include <render/common/BackgroundSphere.h>

class DebugBackgroundRenderer : public Object
{
    BackgroundSphere _sphere;

public:
    DebugBackgroundRenderer();

    void Render();
};
