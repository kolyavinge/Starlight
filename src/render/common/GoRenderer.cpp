#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/GoRenderer.h>

GoRenderer::GoRenderer()
{
    _goItem = nullptr;
    Reset();
}

void GoRenderer::Init(TexturedRect& goItem)
{
    _goItem = &goItem;
}

void GoRenderer::Reset()
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
        (Constants::ScreenWidth - _goItem->GetWidth()) / 2.0f,
        (Constants::ScreenHeight - _goItem->GetHeight()) / 2.0f,
        0.0f);
    _goItem->Render();

    glPopMatrix();
}
