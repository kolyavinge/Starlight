#include <lib/Assert.h>
#include <gl/opengl.h>
#include <render/common/ShipsRenderer.h>

ShipsRenderer::ShipsRenderer(ShipRenderer& shipRenderer) :
    _shipRenderer(shipRenderer)
{
}

void ShipsRenderer::Update()
{
    _shipRenderer.Update();
}

void ShipsRenderer::RenderAllShips(Ship& player, Collection<Ship>& enemies)
{
    RenderPlayer(player);
    RenderEnemies(enemies);
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
    glEnable(GL_DEPTH_TEST);

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

    glDisable(GL_DEPTH_TEST);
}

ShipsRenderer* ShipsRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipsRenderer(resolver.Resolve<ShipRenderer>());
}
