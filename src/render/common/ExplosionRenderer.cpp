#include <gl/opengl.h>
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
            float radians;
            Vector3 pivot;
            ship.Border.GetAngleAndPivot(radians, pivot);
            _animations.Add(AnimatedTexturedRect(*_explosionTexture, 4));
            _animations[_animations.GetCount() - 1].Activate();
            _positions.Add(ship.Border.DownLeft);
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
