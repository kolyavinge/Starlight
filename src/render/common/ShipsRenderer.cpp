#include <gl/opengl.h>
#include <render/common/ShipsRenderer.h>

void ShipsRenderer::Init()
{
    _shipMesh.Init();
}

void ShipsRenderer::Render(Ship& player, List<Ship>& enemies)
{
    glEnable(GL_DEPTH_TEST);

    _shipMesh.Render(player, 0);

    int enemyActiveTextureIndex = 1;
    for (int i = 0; i < enemies.GetCount(); i++)
    {
        _shipMesh.Render(enemies[i], enemyActiveTextureIndex);
        enemyActiveTextureIndex++;
        if (enemyActiveTextureIndex == _shipMesh.GetTexturesCount()) enemyActiveTextureIndex = 1;
    }

    glDisable(GL_DEPTH_TEST);
}
