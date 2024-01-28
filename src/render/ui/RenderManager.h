#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

class RenderManager : public Object
{
    ScreenRendererCollection _rendererCollection;

public:
    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);

private:
    void InitGL();
};
