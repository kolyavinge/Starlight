#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <render/common/ExplosionRenderer.h>

ExplosionRenderer::ExplosionRenderer(GraphicItemCollection& graphicItemCollection) :
    _explosionTexture(graphicItemCollection.ExplosionTexture)
{
}

void ExplosionRenderer::Init()
{
    ClearAnimations();
}

void ExplosionRenderer::Render(Ship& player, Collection<Ship*>& allShips)
{
    RenderAnimations();
    MakeNewAnimations(player, allShips);
    if (AllAnimationsInnactive())
    {
        ClearAnimations();
    }
}

void ExplosionRenderer::RenderAnimations()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glColor3f(1.0f, 1.0f, 1.0f);
    for (int i = 0; i < _animations.GetCount(); i++)
    {
        glPushMatrix();
        glTranslatef(_positions[i]);
        glTranslatef(0.0f, 0.0f, -5.0f);
        glRotatef(Geometry::RadiansToDegrees(_radians[i]), _pivots[i]);
        glScalef(0.1f, 0.1f, 0.1f);
        _animations[i].Render();
        glPopMatrix();
    }
    glDisable(GL_BLEND);
    glDisable(GL_DEPTH_TEST);
}

void ExplosionRenderer::MakeNewAnimations(Ship& player, Collection<Ship*>& allShips)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& ship = *allShips[i];
        if (ship.State == ShipState::Exploded)
        {
            Vector3 unitX(1.0f, 0.0f, 0.0f);
            Vector3 vx(player.Border.DownRight);
            vx.Sub(player.Border.DownLeft);

            Vector3 unitY(0.0f, 1.0f, 0.0f);
            Vector3 vz(player.CentralLine.NormalFront);

            float radians;
            Vector3 pivot;
            Geometry::RotateCoordinateSystem3d(unitX, vx, unitY, vz, radians, pivot);

            _animations.Add(AnimatedTexturedRect(_explosionTexture, 4));
            _animations.Last().Activate();
            _positions.Add(ship.Border.DownLeft);
            _radians.Add(radians);
            _pivots.Add(pivot);
        }
    }
}

bool ExplosionRenderer::AllAnimationsInnactive()
{
    for (int i = 0; i < _animations.GetCount(); i++)
    {
        if (_animations[i].IsActive())
        {
            return false;
        }
    }

    return true;
}

void ExplosionRenderer::ClearAnimations()
{
    _animations.Clear();
    _positions.Clear();
    _radians.Clear();
    _pivots.Clear();
}

ExplosionRenderer* ExplosionRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ExplosionRenderer(resolver.Resolve<GraphicItemCollection>());
}
