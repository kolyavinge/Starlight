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
    _scaleVector.Set(
        ShipMeasure::XLength / meshSize.XLength,
        ShipMeasure::YLength / meshSize.YLength,
        ShipMeasure::ZLength / meshSize.ZLength);
}

void ShipMesh::Render(Ship& ship)
{
    glPushMatrix();
    SetPosition(ship);
    _shipMesh.Render();
    glPopMatrix();
}

void ShipMesh::SetPosition(Ship& ship)
{
    float radians;
    Vector3 pivot;
    ship.Border.GetAngleAndPivot(radians, pivot);
    glTranslatef(ship.Border.DownLeft);
    glRotatef(Geometry::RadiansToDegrees(radians), pivot.X, pivot.Y, pivot.Z);
    glTranslatef(ShipMeasure::XLengthHalf, 0.0f, 0.0f);
    glRotatef(Geometry::RadiansToDegrees(ship.GetRollRadians()), 0.0f, 1.0f, 0.0f);
    glScalef(_scaleVector);
}
