#include <gl/opengl.h>
#include <lib/Numeric.h>
#include <core/Constants.h>
#include <render/dash/DamageEffectRenderer.h>

DamageEffectRenderer::DamageEffectRenderer(GraphicItemCollection& graphicItemCollection) :
    _damageEffectTexture(graphicItemCollection.DamageEffectTexture)
{
    Init();
}

void DamageEffectRenderer::Init()
{
    _alpha = 0.0f;
}

void DamageEffectRenderer::Update(Ship& player)
{
    if (player.IsDamaged)
    {
        _alpha = 0.5f;
    }
    else if (_alpha > 0.0f)
    {
        _alpha -= 0.005f;
        if (_alpha < 0.0f)
        {
            _alpha = 0.0f;
        }
    }
}

void DamageEffectRenderer::Render()
{
    if (Numeric::FloatEquals(_alpha, 0.0f)) return;

    glColor4f(1.0f, 1.0f, 1.0f, _alpha);

    glEnable(GL_TEXTURE_2D);

    _damageEffectTexture.Bind();

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(Constants::ScreenWidth, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(Constants::ScreenWidth, Constants::ScreenHeight);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, Constants::ScreenHeight);

    glEnd();

    glDisable(GL_TEXTURE_2D);
}

DamageEffectRenderer* DamageEffectRendererResolvingFactory::Make(Resolver& resolver)
{
    return new DamageEffectRenderer(
        resolver.Resolve<GraphicItemCollection>());
}
