#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/PowerUpRenderer.h>

PowerUpRenderer::PowerUpRenderer()
{
    _angleDegrees = 0.0f;
    _healthTexture = nullptr;
    _machinegunTexture = nullptr;
}

void PowerUpRenderer::Init(Texture& healthTexture, Texture& machinegunTexture)
{
    _healthTexture = &healthTexture;
    _machinegunTexture = &machinegunTexture;
}

void PowerUpRenderer::Render(IArray<PowerUp>& powerUps)
{
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);
    for (int i = 0; i < powerUps.GetCount(); i++)
    {
        PowerUp& p = powerUps[i];
        if (!p.IsActive) continue;
        BindTexture(p);
        RenderRect(p);
    }
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    _angleDegrees = Geometry::NormalizeDegrees(_angleDegrees + 8.0f);
}

void PowerUpRenderer::BindTexture(PowerUp& powerUp)
{
    if (powerUp.Kind == PowerUpKind::Health)
    {
        _healthTexture->Bind();
    }
    else if (powerUp.Kind == PowerUpKind::Machinegun)
    {
        _machinegunTexture->Bind();
    }
}

void PowerUpRenderer::RenderRect(PowerUp& powerUp)
{
    glPushMatrix();

    glTranslatef(powerUp.Middle);
    glRotatef(_angleDegrees, Constants::UpAxis);

    glBegin(GL_QUADS);

    glTexCoord2i(0, 0);
    glVertex3f(-0.5f, 0.0f, 0.0f);

    glTexCoord2i(1, 0);
    glVertex3f(0.5f, 0.0f, 0.0f);

    glTexCoord2i(1, 1);
    glVertex3f(0.5f, 0.0f, 1.0f);

    glTexCoord2i(0, 1);
    glVertex3f(-0.5f, 0.0f, 1.0f);

    glEnd();

    glPopMatrix();
}
