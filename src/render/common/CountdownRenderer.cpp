#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/CountdownRenderer.h>

CountdownRenderer::CountdownRenderer()
{
    _countdownItems.InitZero();
}

void CountdownRenderer::Init(
    TexturedRect& countdown1Item,
    TexturedRect& countdown2Item,
    TexturedRect& countdown3Item)
{
    _countdownItems[1] = &countdown1Item;
    _countdownItems[2] = &countdown2Item;
    _countdownItems[3] = &countdown3Item;
}

void CountdownRenderer::Render(int countdownNumber, int countdownIteration, int countdownSwitchIteration)
{
    float alpha = 1.0f - (float)countdownIteration * 1.0f / (float)countdownSwitchIteration;
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, alpha);

    glPushMatrix();

    TexturedRect* currentItem = _countdownItems[countdownNumber];
    glTranslatef(
        (Constants::ScreenWidth - currentItem->GetWidth()) / 2.0f,
        (Constants::ScreenHeight - currentItem->GetHeight()) / 2.0f + currentItem->GetHeight(),
        0.0f);

    currentItem->Render();

    glPopMatrix();
}

CountdownRenderer* CountdownRendererResolvingFactory::Make(Resolver&)
{
    return new CountdownRenderer();
}
