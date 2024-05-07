#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/dash/CompleteLapTimeRenderer.h>

CompleteLapTimeRenderer::CompleteLapTimeRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
    _completeLapsCount = 0;
    _lastLapMessageString = String(L"LAST LAP");
    _alpha = 0.0f;
}

void CompleteLapTimeRenderer::Init()
{
    _completeLapsCount = 0;
    _alpha = 0.0f;
}

void CompleteLapTimeRenderer::Render(Laps& laps)
{
    if (_completeLapsCount != laps.GetCompleteLapsCount())
    {
        _completeLapsCount = laps.GetCompleteLapsCount();
        _lastLapTime.Clear();
        laps.GetCompletedLapTime(_completeLapsCount, _lastLapTime);
        _alpha = 1.0f;
    }

    if (_alpha < 0.0f) return;

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, _alpha);
    _alpha -= 0.008f;
    RenderLapTime();
    if (laps.IsLastLap())
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

CompleteLapTimeRenderer* CompleteLapTimeRendererResolvingFactory::Make(Resolver& resolver)
{
    return new CompleteLapTimeRenderer(resolver.Resolve<TextRenderer>());
}
