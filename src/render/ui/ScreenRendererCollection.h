#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>

class ScreenRendererCollection : public Object
{
    Array<ScreenRenderer*, 4> _renderers;

public:
    ScreenRendererCollection();
    ~ScreenRendererCollection();

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};
