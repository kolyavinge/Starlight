#include <gl/opengl.h>
#include <render/common/ShipsRenderer.h>

void ShipsRenderer::Init()
{
    _shipMesh.Init();
}

void ShipsRenderer::Render(Ship& player, List<Ship>& enemies)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    _shipMesh.Render(player, 0);
    for (int i = 0; i < enemies.Count(); i++)
    {
        _shipMesh.Render(enemies[i], i + 1);
    }
    glDisable(GL_DEPTH_TEST);
}
