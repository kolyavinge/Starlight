#include <gl/opengl.h>
#include <render/release/ShipRenderer.h>

void ShipRenderer::Render(Ship& ship)
{
    _shipMesh.Render(ship);
}
