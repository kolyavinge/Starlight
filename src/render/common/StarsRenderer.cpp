#include <gl/opengl.h>
#include <lib/Random.h>
#include <lib/Math.h>
#include <calc/Geometry.h>
#include <render/common/BackgroundSphere.h>
#include <render/common/StarsRenderer.h>

StarsRenderer::StarsRenderer() :
    _stars(BackgroundSphere::Radius, 150)
{
    InitGlow();
}

void StarsRenderer::Render()
{
    glEnable(GL_BLEND);
    glBegin(GL_POINTS);

    for (int i = 0; i < _stars.GetPointsCount(); i++)
    {
        _glow[i] = Geometry::NormalizeRadians(_glow[i] + _glowSteps[i]);
        float alpha = Math::Abs(Math::Sin(_glow[i]));
        glColor4f(1.0f, 1.0f, 1.0f, alpha);
        glVertex3f(_stars.GetPoint(i));
    }

    glEnd();
    glDisable(GL_BLEND);
}

void StarsRenderer::InitGlow()
{
    Random rand;
    for (int i = 0; i < _stars.GetPointsCount(); i++)
    {
        _glow.Add(rand.GetFloatFromZeroToOne());
        _glowSteps.Add(rand.GetFloatFromZeroToN(0.1f));
    }
}

StarsRenderer* StarsRendererResolvingFactory::Make(Resolver&)
{
    return new StarsRenderer();
}
