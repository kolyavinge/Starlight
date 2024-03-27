#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/GoRenderer.h>

GoRenderer::GoRenderer(GraphicItemCollection& graphicItemCollection) :
    _goItem(graphicItemCollection.GoItem)
{
    Init();
}

void GoRenderer::Init()
{
    _alpha = 1.0f;
}

void GoRenderer::Render()
{
    if (_alpha < 0.0f) return;

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, _alpha);
    _alpha -= 0.01f;

    glPushMatrix();

    glTranslatef(
        (Constants::ScreenWidth - _goItem.GetWidth()) / 2.0f,
        (Constants::ScreenHeight - _goItem.GetHeight()) / 2.0f,
        0.0f);
    _goItem.Render();

    glPopMatrix();
}

GoRenderer* GoRendererResolvingFactory::Make(Resolver& resolver)
{
    return new GoRenderer(resolver.Resolve<GraphicItemCollection>());
}
