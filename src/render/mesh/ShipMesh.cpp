#include <model/ShipMeasure.h>
#include <anx/GraphicResources.h>
#include <render/mesh/ShipMesh.h>

ShipMesh::ShipMesh()
{
    _mesh.Load(GraphicResources::GetShipMeshFilePath());
    _mesh.SwapYZ();
    _mesh.MoveToOrigin();
    _mesh.MoveToCenter((int)Mesh::Axis::X);
    _mesh.InvertFacing();
    Mesh::Size meshSize;
    _mesh.GetSize(meshSize);
    _mesh.SetScale(
        ShipMeasure::XLength / meshSize.XLength,
        ShipMeasure::YLength / meshSize.YLength,
        ShipMeasure::ZLength / meshSize.ZLength);
}

Mesh& ShipMesh::GetMesh()
{
    return _mesh;
}

ShipMesh* ShipMeshResolvingFactory::Make(Resolver&)
{
    return new ShipMesh();
}
