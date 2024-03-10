#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>
#include <anx/GraphicResources.h>
#include <render/common/ShipMesh.h>

void ShipMesh::Init()
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

void ShipMesh::Render(Ship& ship, int textureIndex)
{
    glPushMatrix();
    SetPosition(ship);
    _vboMeshRenderer.SetActiveTextureIndex(textureIndex);
    _vboMeshRenderer.Render();
    glPopMatrix();
}

int ShipMesh::GetTexturesCount()
{
    return _shipMesh.Textures.GetCount();
}

void ShipMesh::SetPosition(Ship& ship)
{
    float radians;
    Vector3 pivot;
    ship.Border.GetAngleAndPivot(radians, pivot);
    glTranslatef(ship.Border.DownLeft);
    glRotatef(Geometry::RadiansToDegrees(radians), pivot);
    glTranslatef(ShipMeasure::XLengthHalf, 0.0f, 0.0f);
    glRotatef(Geometry::RadiansToDegrees(ship.GetRollRadians()), 0.0f, 1.0f, 0.0f);
}
