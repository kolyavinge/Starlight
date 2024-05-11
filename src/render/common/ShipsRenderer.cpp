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
    _shipRenderer.Render(player, ShipMesh::PlayerTexture);
}

void ShipsRenderer::RenderEnemies(Collection<Ship>& enemies)
{
    int enemyTexture = ShipMesh::Enemy1Texture;
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        _shipRenderer.Render(enemies[i], enemyTexture);
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

ShipsRenderer* ShipsRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipsRenderer(resolver.Resolve<ShipRenderer>());
}
