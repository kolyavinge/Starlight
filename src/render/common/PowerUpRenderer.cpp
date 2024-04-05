#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/common/PowerUpRenderer.h>

PowerUpRenderer::PowerUpRenderer(GraphicItemCollection& graphicItemCollection) :
    _healthTexture(graphicItemCollection.PowerUpHealthTexture),
    _machinegunTexture(graphicItemCollection.PowerUpMachinegunTexture),
    _nitroTexture(graphicItemCollection.PowerUpNitroTexture)
{
    _angleDegrees = 0.0f;
}

void PowerUpRenderer::Render(IArray<PowerUp>& powerUps)
{
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glEnable(GL_BLEND);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    for (int i = 0; i < powerUps.GetCount(); i++)
    {
        PowerUp& p = powerUps[i];
        if (!p.IsActive) continue;
        BindTexture(p);
        RenderRect(p);
    }
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    _angleDegrees = Geometry::NormalizeDegrees(_angleDegrees + 8.0f);
}

void PowerUpRenderer::BindTexture(PowerUp& powerUp)
{
    if (powerUp.Kind == PowerUpKind::Health)
    {
        _healthTexture.Bind();
    }
    else if (powerUp.Kind == PowerUpKind::Machinegun)
    {
        _machinegunTexture.Bind();
    }
    else if (powerUp.Kind == PowerUpKind::Nitro)
    {
        _nitroTexture.Bind();
    }
}

void PowerUpRenderer::RenderRect(PowerUp& powerUp)
{
    glPushMatrix();

    glTranslatef(powerUp.Middle);
    glTranslatef(0.0f, 0.0f, 0.5f);
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

PowerUpRenderer* PowerUpRendererResolvingFactory::Make(Resolver& resolver)
{
    return new PowerUpRenderer(resolver.Resolve<GraphicItemCollection>());
}
