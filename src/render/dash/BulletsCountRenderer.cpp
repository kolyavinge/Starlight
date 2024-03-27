#include <gl/opengl.h>
#include <lib/NumericConverter.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/dash/BulletsCountRenderer.h>

BulletsCountRenderer::BulletsCountRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
}

void BulletsCountRenderer::Render(Weapon& weapon)
{
    _bulletsString.Clear();
    NumericConverter::IntToString(weapon.GetRemainingBullets(), _bulletsString);
    _bulletsString.Append(L'/');
    NumericConverter::IntToString(weapon.GetMaxBulletsCount(), _bulletsString);

    glColor3f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor);
    glPushMatrix();
    float width = (float)_bulletsString.GetLength() * _textRenderer.GetLetterWidth();
    glTranslatef((Constants::ScreenWidth - width - 10.0f), 10.0f, 0.0f);
    _textRenderer.Render(_bulletsString);
    glPopMatrix();
}

BulletsCountRenderer* BulletsCountRendererResolvingFactory::Make(Resolver& resolver)
{
    return new BulletsCountRenderer(resolver.Resolve<TextRenderer>());
}
