#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/CompleteLapTimeRenderer.h>

CompleteLapTimeRenderer::CompleteLapTimeRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
    _lastLapNumber = 0;
    _lastLapMessageString = String(L"LAST LAP");
    _alpha = 0.0f;
}

void CompleteLapTimeRenderer::Init()
{
    _lastLapNumber = 1;
    _alpha = 0.0f;
}

void CompleteLapTimeRenderer::Render(Laps& laps)
{
    if (_lastLapNumber != laps.GetCurrentLapNumber())
    {
        _lastLapTime.Clear();
        laps.GetCompletedLapTime(_lastLapNumber, _lastLapTime);
        _lastLapNumber = laps.GetCurrentLapNumber();
        _alpha = 1.0f;
    }

    if (_alpha < 0.0f) return;

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, _alpha);
    _alpha -= 0.008f;
    RenderLapTime();
    if (laps.GetCurrentLapNumber() == laps.GetLapsCount())
    {
        RenderLastLap();
    }
}

void CompleteLapTimeRenderer::RenderLapTime()
{
    glPushMatrix();
    float width = (float)_lastLapTime.GetLength() * _textRenderer.GetLetterWidth();
    float height = _textRenderer.GetLetterHeight();
    glTranslatef(
        (Constants::ScreenWidth - width) / 2.0f,
        (Constants::ScreenHeight - height) / 2.0f + Constants::ScreenHeight / 4.0f,
        0.0f);
    _textRenderer.Render(_lastLapTime);
    glPopMatrix();
}

void CompleteLapTimeRenderer::RenderLastLap()
{
    glPushMatrix();
    float width = (float)_lastLapMessageString.GetLength() * _textRenderer.GetLetterWidth();
    float height = _textRenderer.GetLetterHeight();
    glTranslatef(
        (Constants::ScreenWidth - width) / 2.0f,
        (Constants::ScreenHeight - height) / 2.0f + Constants::ScreenHeight / 4.0f - height,
        0.0f);
    _textRenderer.Render(_lastLapMessageString);
    glPopMatrix();
}
