#include <gl/opengl.h>
#include <lib/NumericConverter.h>
#include <render/common/RenderConstants.h>
#include <render/dash/HealthRenderer.h>

HealthRenderer::HealthRenderer(TextRenderer& textRenderer) :
    _textRenderer(textRenderer)
{
}

void HealthRenderer::Render(Ship& player)
{
    _healthValueText.Clear();
    NumericConverter::IntToString((int)(player.Health * 100.0f), _healthValueText);

    if (player.Health <= 0.25f)
    {
        glColor3f(0.7f, 0.0f, 0.0f);
    }
    else
    {
        glColor3f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor);
    }
    glPushMatrix();

    glTranslatef(10.0f, 10.0f, 0.0f);
    _textRenderer.Render(_healthValueText);

    const float barWidth = 200.0f * player.Health;
    const float barHeight = 20.0f;
    glTranslatef(85.0f, 12.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(barWidth, 0.0f, 0.0f);
    glVertex3f(barWidth, barHeight, 0.0f);
    glVertex3f(0.0f, barHeight, 0.0f);
    glEnd();

    glPopMatrix();
}

HealthRenderer* HealthRendererResolvingFactory::Make(Resolver& resolver)
{
    return new HealthRenderer(resolver.Resolve<TextRenderer>());
}
