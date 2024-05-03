#include <gl/opengl.h>
#include <lib/Assert.h>
#include <render/common/ShipsRenderer.h>

ShipsRenderer::ShipsRenderer(ShipRenderer& shipRenderer) :
    _shipRenderer(shipRenderer)
{
}

void ShipsRenderer::Update()
{
    _shipRenderer.Update();
}

void ShipsRenderer::Render(Ship& player, Collection<Ship>& enemies)
{
    glEnable(GL_DEPTH_TEST);
    RenderPlayer(player);
    RenderEnemies(enemies);
    glDisable(GL_DEPTH_TEST);
}

void ShipsRenderer::RenderPlayer(Ship& player)
{
    RenderShip(player, ShipMesh::PlayerTexture);
}

void ShipsRenderer::RenderEnemies(Collection<Ship>& enemies)
{
    int enemyTexture = ShipMesh::Enemy1Texture;
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        RenderShip(enemies[i], enemyTexture);
        if (enemyTexture == ShipMesh::Enemy3Texture)
        {
            enemyTexture = ShipMesh::Enemy1Texture;
        }
        else
        {
            enemyTexture++;
        }
    }
}

void ShipsRenderer::RenderShip(Ship& ship, int defaultTexture)
{
    if (ship.State == ShipState::Active)
    {
        _shipRenderer.Render(ship, defaultTexture);
    }
    else if (ship.State == ShipState::Exploded || ship.State == ShipState::Destroyed)
    {
        _shipRenderer.Render(ship, ShipMesh::DestroyedTexture);
    }
    else if (ship.State == ShipState::Reseted || ship.State == ShipState::Prepared)
    {
        if ((ship.DelayIterations % 10) == 0) // мерцание кораблика
        {
            _shipRenderer.Render(ship, defaultTexture);
        }
    }
    else
    {
        Assert::Fail();
    }
}

ShipsRenderer* ShipsRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipsRenderer(resolver.Resolve<ShipRenderer>());
}
