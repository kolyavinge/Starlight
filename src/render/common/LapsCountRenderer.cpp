#include <gl/opengl.h>
#include <lib/NumericConverter.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/LapsCountRenderer.h>

LapsCountRenderer::LapsCountRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
}

void LapsCountRenderer::Render(Laps& laps)
{
    _lapsCountString.Clear();
    NumericConverter::IntToString(laps.GetCurrentLapNumber(), _lapsCountString);
    _lapsCountString.Append(L'/');
    NumericConverter::IntToString(laps.GetLapsCount(), _lapsCountString);

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glPushMatrix();

    float lapsCountStringWidth = _lapsCountString.GetLength() * _textRenderer.GetLetterWidth();
    glTranslatef(
        (Constants::ScreenWidth - lapsCountStringWidth) / 2.0f,
        Constants::ScreenHeight - _textRenderer.GetLetterHeight(),
        0.0f);
    _textRenderer.Render(_lapsCountString);

    glPopMatrix();
}
