#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <render/ui/ScreenRenderer.h>
#include <render/ui/ScreenRendererCollection.h>

class RenderManagerException : public Exception { };

class RenderManager : public Object
{
    ScreenRendererCollection _rendererCollection;

public:
    void Init();
    ScreenRenderer& GetScreenRenderer(Screen& screen);

private:
    void InitGL();
};

class RenderManagerResolvingFactory : public ResolvingFactory<RenderManager>
{
public:
    RenderManager* Make(Resolver& resolver) override;
};
