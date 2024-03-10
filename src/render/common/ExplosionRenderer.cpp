#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <calc/Quaternion.h>
#include <render/common/ExplosionRenderer.h>

ExplosionRenderer::ExplosionRenderer()
{
    _explosionTexture = nullptr;
}

void ExplosionRenderer::Init(FramedTexture& explosionTexture)
{
    _explosionTexture = &explosionTexture;
}

void ExplosionRenderer::Render(IArray<Ship*>& allShips)
{
    RenderAnimations();
    MakeNewAnimations(allShips);
    if (AllAnimationsInnactive())
    {
        _animations.Clear();
        _positions.Clear();
        _radians.Clear();
        _pivots.Clear();
    }
}

void ExplosionRenderer::RenderAnimations()
{
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
}

void ExplosionRenderer::MakeNewAnimations(IArray<Ship*>& allShips)
{
    for (int i = 0; i < allShips.GetCount(); i++)
    {
        Ship& ship = *allShips[i];
        if (ship.State == ShipState::Exploded)
        {
            Vector3 unitX(1.0f, 0.0f, 0.0f);
            Vector3 vx(ship.Border.DownRight);
            vx.Sub(ship.Border.DownLeft);

            Vector3 unitZ(0.0f, 0.0f, 1.0f);
            Vector3 vy(ship.CentralLine.Front);
            vy.Sub(ship.CentralLine.Rear);

            Quaternion result(unitX, vx);
            result.RotatePoint(vy);
            Quaternion qz(vy, unitZ);
            result.Mul(qz);

            float radians;
            Vector3 pivot;
            result.GetAngleAndPivot(radians, pivot);

            _animations.Add(AnimatedTexturedRect(*_explosionTexture, 4));
            _animations[_animations.GetCount() - 1].Activate();
            _positions.Add(ship.CentralLine.Front);
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
