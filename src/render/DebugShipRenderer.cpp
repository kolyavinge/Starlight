#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <render/DebugShipRenderer.h>

void DebugShipRenderer::Render(Ship& ship)
{
    RenderMiddleLine(ship);
    RenderBorder(ship);
    RenderBorderPoints(ship);
    RenderTurnAngle(ship);
    _shipMesh.Render(ship);
}

void DebugShipRenderer::RenderMiddleLine(Ship& ship)
{
    glColor3f(0.4f, 0.4f, 0.4f);

    glBegin(GL_LINES);

    glVertex3f(ship.CentralLine.Front);
    glVertex3f(ship.CentralLine.Rear);

    glEnd();
}

void DebugShipRenderer::RenderTurnAngle(Ship& ship)
{
    float angleBetween = GetAngleBetweenShipAndYStraight(ship);

    glPushMatrix();

    glTranslatef(ship.CentralLine.Rear);
    glRotatef(Geometry::RadiansToDegrees(angleBetween + ship.TurnAngleRadians), 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 0.6f, 0.0f);

    glBegin(GL_LINES);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.25f, 0.0f);

    glEnd();

    glPopMatrix();
}

void DebugShipRenderer::RenderBorder(Ship& ship)
{
    glColor3f(0.4f, 0.4f, 0.4f);

    glBegin(GL_LINE_LOOP);

    glVertex3f(ship.Border.UpLeft);
    glVertex3f(ship.Border.UpRight);
    glVertex3f(ship.Border.DownRight);
    glVertex3f(ship.Border.DownLeft);

    glEnd();
}

void DebugShipRenderer::RenderBorderPoints(Ship& ship)
{
    glColor3f(0.6f, 0.6f, 0.6f);

    glBegin(GL_POINTS);

    glVertex3f(ship.Border.UpLeft);
    glVertex3f(ship.Border.UpRight);
    glVertex3f(ship.Border.DownRight);
    glVertex3f(ship.Border.DownLeft);

    glEnd();

    glPushMatrix();
    glTranslatef(0.0f, 0.0f, ShipMeasure::ZLength);
    glBegin(GL_POINTS);

    glVertex3f(ship.Border.UpLeft);
    glVertex3f(ship.Border.UpRight);
    glVertex3f(ship.Border.DownRight);
    glVertex3f(ship.Border.DownLeft);

    glEnd();
    glPopMatrix();
}

float DebugShipRenderer::GetAngleBetweenShipAndYStraight(Ship& ship)
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
