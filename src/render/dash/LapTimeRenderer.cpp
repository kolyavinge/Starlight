#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/dash/LapTimeRenderer.h>

LapTimeRenderer::LapTimeRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
}

void LapTimeRenderer::Render(Laps& laps)
{
    _lapTimeString.Clear();
    laps.GetCurrentLapTime(_lapTimeString);

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glPushMatrix();

    float lapTimeStringWidth = _lapTimeString.GetLength() * _textRenderer.GetLetterWidth();
    glTranslatef(
        Constants::ScreenWidth - lapTimeStringWidth - 10.0f,
        Constants::ScreenHeight - _textRenderer.GetLetterHeight(),
        0.0f);
    _textRenderer.Render(_lapTimeString);

    glPopMatrix();
}
