#include <gl/opengl.h>
#include <lib/Assert.h>
#include <render/common/ShipsRenderer.h>

void ShipsRenderer::Init()
{
    _shipMesh.Init();
}

void ShipsRenderer::Render(Ship& player, IArray<Ship>& enemies)
{
    glEnable(GL_DEPTH_TEST);

    RenderShip(player, ShipMesh::PlayerTexture);

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

    glDisable(GL_DEPTH_TEST);
}

void ShipsRenderer::RenderShip(Ship& ship, int defaultTexture)
{
    if (ship.State == ShipState::Active || ship.State == ShipState::Reseted)
    {
        _shipMesh.Render(ship, defaultTexture);
    }
    else if (ship.State == ShipState::Exploded || ship.State == ShipState::Destroyed)
    {
        _shipMesh.Render(ship, ShipMesh::DestroyedTexture);
    }
    else
    {
        Assert::Fail();
    }
}
