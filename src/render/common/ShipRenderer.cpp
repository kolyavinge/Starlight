#include <render/common/ShipRenderer.h>

ShipRenderer::ShipRenderer(ShipMesh& shipMesh) :
    _shipMesh(shipMesh)
{
}

void ShipRenderer::Init()
{
    _shipMesh.Init();
}

void ShipRenderer::Render(Ship& ship, int textureIndex)
{
    _shipMesh.Render(ship, textureIndex);
}

ShipRenderer* ShipRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipRenderer(resolver.Resolve<ShipMesh>());
}
