#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/ui/RenderManager.h>

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
}
