#include <render/ui/RenderManager.h>

RenderManager::RenderManager(ScreenRendererCollection& rendererCollection) :
    _rendererCollection(rendererCollection)
{
}

void RenderManager::Init()
{
    _rendererCollection.Init();
}

ScreenRenderer& RenderManager::GetScreenRenderer(Screen& screen)
{
    return _rendererCollection.GetScreenRenderer(screen);
}

RenderManager* RenderManagerResolvingFactory::Make(Resolver& resolver)
{
    return new RenderManager(resolver.Resolve<ScreenRendererCollection>());
}
