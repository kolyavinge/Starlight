#include <gl/opengl.h>
#include <lib/Math.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <render/ShipMesh.h>

//#define GL_POLYGON_TYPE GL_POLYGON
#define GL_POLYGON_TYPE GL_LINE_LOOP

void ShipMesh::Render(Ship& ship)
{
    glColor3f(0.7f, 0.7f, 0.7f);
    glPushMatrix();
    SetPosition(ship);
    RenderBody();
    RenderFrontWings();
    RenderRearWings();
    RenderRearSmallWings();
    RenderTurbines();
    glPopMatrix();
}

void ShipMesh::SetPosition(Ship& ship)
{
    glTranslatef(ship.Border.DownLeft);
    float angle = Geometry::RadiansToDegrees(GetAngleBetweenShipAndYStraight(ship));
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glTranslatef(ShipMeasure::XLengthHalf, 0.0f, 0.0f);
}

void ShipMesh::RenderBody()
{
    RenderUpBody();
    RenderDownBody();
    RenderCabin();
}

void ShipMesh::RenderUpBody()
{
    // верхняя часть
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.2f, 0.0f, 0.5f);
    glVertex3f(-0.15f, 1.0f, 0.5f);
    glVertex3f(0.15f, 1.0f, 0.5f);
    glVertex3f(0.2f, 0.0f, 0.5f);
    glEnd();

    // зад
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.2f, 0.0f, 0.5f);
    glVertex3f(-0.23f, 0.0f, 0.25f);
    glVertex3f(0.23f, 0.0f, 0.25f);
    glVertex3f(0.2f, 0.0f, 0.5f);
    glEnd();

    // левый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.2f, 0.0f, 0.5f);
    glVertex3f(-0.15f, 1.0f, 0.5f);
    glVertex3f(-0.2f, 1.0f, 0.25f);
    glVertex3f(-0.23f, 0.0f, 0.25f);
    glEnd();

    // правый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.2f, 0.0f, 0.5f);
    glVertex3f(0.15f, 1.0f, 0.5f);
    glVertex3f(0.2f, 1.0f, 0.25f);
    glVertex3f(0.23f, 0.0f, 0.25f);
    glEnd();
}

void ShipMesh::RenderDownBody()
{
    // нижняя часть
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.2f, 1.0f, 0.25f);
    glVertex3f(-0.1f, 2.2f, 0.25f);
    glVertex3f(0.1f, 2.2f, 0.25f);
    glVertex3f(0.2f, 1.0f, 0.25f);
    glEnd();

    // левый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.2f, 1.0f, 0.25f);
    glVertex3f(-0.1f, 2.2f, 0.25f);
    glVertex3f(-0.1f, 2.2f, 0.0f);
    glVertex3f(-0.2f, 1.0f, 0.0f);
    glEnd();

    // правый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.2f, 1.0f, 0.25f);
    glVertex3f(0.1f, 2.2f, 0.25f);
    glVertex3f(0.1f, 2.2f, 0.0f);
    glVertex3f(0.2f, 1.0f, 0.0f);
    glEnd();
}

void ShipMesh::RenderCabin()
{
    // верх
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.15f, 1.0f, 0.5f);
    glVertex3f(-0.1f, 1.5f, 0.35f);
    glVertex3f(0.1f, 1.5f, 0.35f);
    glVertex3f(0.15f, 1.0f, 0.5f);
    glEnd();

    // перед
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.1f, 1.5f, 0.35f);
    glVertex3f(-0.15f, 1.5f, 0.25f);
    glVertex3f(0.15f, 1.5f, 0.25f);
    glVertex3f(0.1f, 1.5f, 0.35f);
    glEnd();

    // левый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.15f, 1.0f, 0.5f);
    glVertex3f(-0.1f, 1.5f, 0.35f);
    glVertex3f(-0.19f, 1.5f, 0.2f);
    glVertex3f(-0.2f, 1.0f, 0.23f);
    glEnd();

    // правый бок
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.15f, 1.0f, 0.5f);
    glVertex3f(0.1f, 1.5f, 0.35f);
    glVertex3f(0.19f, 1.5f, 0.2f);
    glVertex3f(0.2f, 1.0f, 0.23f);
    glEnd();
}

void ShipMesh::RenderFrontWings()
{
    glPushMatrix();
    glTranslatef(-0.11f, 2.0f, 0.0f);
    RenderFrontWing();

    glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
    glTranslatef(-0.22f, 0.0f, 0.0f);
    RenderFrontWing();
    glPopMatrix();
}

void ShipMesh::RenderFrontWing()
{
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(-0.5f, 0.2f, 0.0f);
    glVertex3f(-0.4f, 0.5f, 0.0f);
    glVertex3f(-0.3f, 0.5f, 0.0f);
    glVertex3f(-0.3f, 0.3f, 0.0f);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glEnd();
}

void ShipMesh::RenderRearWings()
{
    glPushMatrix();
    glTranslatef(-0.15f, 0.0f, 0.0f);
    RenderRearWing();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.15f, 0.0f, 0.0f);
    RenderRearWing();
    glPopMatrix();
}

void ShipMesh::RenderRearWing()
{
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.2f);

    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.0f, 0.0f, 0.4f);
    glVertex3f(0.0f, 0.4f, 0.4f);
    glVertex3f(-0.5f, 0.4f, 0.5f);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glEnd();

    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.5f, 0.0f, 0.5f);
    glVertex3f(-0.5f, 0.4f, 0.5f);
    glVertex3f(-1.0f, 0.4f, 0.4f);
    glVertex3f(-1.0f, 0.0f, 0.4f);
    glEnd();

    glPopMatrix();
}

void ShipMesh::RenderRearSmallWings()
{
    glBegin(GL_POLYGON_TYPE);
    glVertex3f(-0.23f, 0.0f, 0.25f);
    glVertex3f(-0.23f, 0.2f, 0.25f);
    glVertex3f(-0.5f, 0.2f, 0.1f);
    glVertex3f(-0.5f, 0.0f, 0.1f);
    glEnd();

    glBegin(GL_POLYGON_TYPE);
    glVertex3f(0.23f, 0.0f, 0.25f);
    glVertex3f(0.23f, 0.2f, 0.25f);
    glVertex3f(0.5f, 0.2f, 0.1f);
    glVertex3f(0.5f, 0.0f, 0.1f);
    glEnd();
}

void ShipMesh::RenderTurbines()
{
}

void ShipMesh::RenderTurbine()
{
}

float ShipMesh::GetAngleBetweenShipAndYStraight(Ship& ship)
{
    Vector3d v(ship.CentralLine.Front);
    v.Sub(ship.CentralLine.Rear);
    v.Normalize();
    Vector3d straight(0.0f, 1.0f, 0.0f);
    float cosAlpha = v.DotProduct(straight);
    float alpha = Math::ArcCos(cosAlpha);
    if (v.X > 0.0f) alpha = -alpha;

    return alpha;
}
