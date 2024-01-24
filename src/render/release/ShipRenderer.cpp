#include <gl/opengl.h>
#include <render/release/ShipRenderer.h>

void ShipRenderer::Init()
{
    _shipMesh.Init();
}

void ShipRenderer::Render(Ship& ship)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    _shipMesh.Render(ship);
    glDisable(GL_DEPTH_TEST);
}
