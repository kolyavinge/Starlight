#include <model/ShipMeasure.h>
#include <anx/GraphicResources.h>
#include <render/common/ShipMeshRenderer.h>

ShipMeshRenderer::ShipMeshRenderer()
{
    _shipMesh.Load(GraphicResources::GetShipMeshFilePath());
    _shipMesh.SwapYZ();
    _shipMesh.MoveToOrigin();
    _shipMesh.MoveToCenter((int)Mesh::Axis::X);
    Mesh::Size meshSize;
    _shipMesh.GetSize(meshSize);
    _shipMesh.SetScale(
        ShipMeasure::XLength / meshSize.XLength,
        ShipMeasure::YLength / meshSize.YLength,
        ShipMeasure::ZLength / meshSize.ZLength);
    _vboMeshRenderer.Init(_shipMesh);
}

void ShipMeshRenderer::Render(int textureIndex)
{
    _vboMeshRenderer.SetActiveTextureIndex(textureIndex);
    _vboMeshRenderer.Render();
}

int ShipMeshRenderer::GetTexturesCount()
{
    return _shipMesh.Textures.GetCount();
}

ShipMeshRenderer* ShipMeshRendererResolvingFactory::Make(Resolver&)
{
    return new ShipMeshRenderer();
}
