#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

class RenderManager : public Object
{
    ScreenRendererCollection& _rendererCollection;

public:
    RenderManager(ScreenRendererCollection& rendererCollection);

    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);
};

class RenderManagerResolvingFactory : public ResolvingFactory<RenderManager>
{
public:
    RenderManager* Make(Resolver& resolver) override;
};
