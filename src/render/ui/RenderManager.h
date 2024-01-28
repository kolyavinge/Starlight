#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>

class RenderManager : public Object
{
    Array<ScreenRenderer*, 4> _renderers;

public:
    RenderManager();
    ~RenderManager();

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};
