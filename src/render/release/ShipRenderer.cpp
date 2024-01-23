#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <core/Resources.h>
#include <render/release/ShipRenderer.h>

void ShipRenderer::Init()
{
    _shipMesh.Load(Resources::GetShipMeshFilePath());
    _shipMesh.SwapYZ();
    _shipMesh.MoveToCenter(Mesh::Axis::X);
    _scaleVector.Set(
        ShipMeasure::XLength / _shipMesh.GetXLength(),
        ShipMeasure::YLength / _shipMesh.GetYLength(),
        ShipMeasure::ZLength / _shipMesh.GetZLength());
}

void ShipRenderer::Render(Ship& ship)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    SetPosition(ship);
    _shipMesh.Render();
    glPopMatrix();
    glDisable(GL_DEPTH_TEST);
}

void ShipRenderer::SetPosition(Ship& ship)
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
