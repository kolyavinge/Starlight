#include <gl/opengl.h>
#include <render/common/ShipsRenderer.h>

void ShipsRenderer::Init()
{
    _shipMesh.Init();
}

void ShipsRenderer::Render(Ship& player, IArray<Ship>& enemies)
{
    glEnable(GL_DEPTH_TEST);

    _shipMesh.Render(player, ShipMesh::PlayerTexture);

    int enemyActiveTexture = ShipMesh::Enemy1Texture;
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        _shipMesh.Render(enemies[i], enemyActiveTexture);
        if (enemyActiveTexture == ShipMesh::Enemy3Texture)
        {
            enemyActiveTexture = ShipMesh::Enemy1Texture;
        }
        else
        {
            enemyActiveTexture++;
        }
    }

    glDisable(GL_DEPTH_TEST);
}
