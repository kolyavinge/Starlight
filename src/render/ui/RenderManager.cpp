#include <glew/glew.h>
#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/ui/RenderManager.h>

RenderManager::RenderManager(ScreenRendererCollection& rendererCollection) :
    _rendererCollection(rendererCollection)
{
}

void RenderManager::Init()
{
    InitGL();
    _rendererCollection.Init();
}

ScreenRenderer& RenderManager::GetScreenRenderer(Screen& screen)
{
    return _rendererCollection.GetScreenRenderer(screen);
}

void RenderManager::InitGL()
{
    glPointSize(Constants::RenderPointSize);
    glLineWidth(Constants::RenderLineWidth);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    if (glewInit() != GLEW_NO_ERROR) throw RenderManagerException();
}

RenderManager* RenderManagerResolvingFactory::Make(Resolver& resolver)
{
    return new RenderManager(resolver.Resolve<ScreenRendererCollection>());
}
