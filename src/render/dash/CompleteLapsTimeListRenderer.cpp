#include <gl/opengl.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/dash/CompleteLapsTimeListRenderer.h>

CompleteLapsTimeListRenderer::CompleteLapsTimeListRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
}

void CompleteLapsTimeListRenderer::Render(Laps& laps)
{
    // last time on top
    float y = Constants::ScreenHeight - _textRenderer.GetLetterHeight() - _textRenderer.GetLetterHeight();
    for (int lapNumber = laps.GetCompleteLapsCount(); lapNumber > 0; lapNumber--)
    {
        _lapTimeString.Clear();
        laps.GetCompletedLapTime(lapNumber, _lapTimeString);

        glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 0.8f);
        glPushMatrix();

        float lapTimeStringWidth = _scale * _lapTimeString.GetLength() * _textRenderer.GetLetterWidth();
        glTranslatef(Constants::ScreenWidth - lapTimeStringWidth, y, 0.0f);
        glScalef(_scale, _scale, _scale);
        _textRenderer.Render(_lapTimeString);
        y -= _scale * _textRenderer.GetLetterHeight();

        glPopMatrix();
    }
}

CompleteLapsTimeListRenderer* CompleteLapsTimeListRendererResolvingFactory::Make(Resolver& resolver)
{
    return new CompleteLapsTimeListRenderer(resolver.Resolve<TextRenderer>());
}
