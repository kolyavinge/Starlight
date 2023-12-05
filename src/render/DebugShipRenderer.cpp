#include "gl/opengl.h"
#include "lib/Math.h"
#include "calc/Geometry.h"
#include "render/DebugShipRenderer.h"

void DebugShipRenderer::Render(Ship& ship)
{
    RenderMiddleLine(ship);
    RenderTurnAngle(ship);
    RenderBorder(ship);
}

void DebugShipRenderer::RenderMiddleLine(Ship& ship)
{
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);

    glVertex3f(ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y, ship.FrontMiddlePoint.Z);
    glVertex3f(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y, ship.RearMiddlePoint.Z);

    glEnd();
}

void DebugShipRenderer::RenderTurnAngle(Ship& ship)
{
    float angleBetween = GetAngleBetweenShipAndYStraight(ship);

    glPushMatrix();

    glTranslatef(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y, ship.RearMiddlePoint.Z);
    glRotatef(Geometry::RadiansToDegrees(angleBetween + ship.TurnAngleRadians), 0.0f, 0.0f, 1.0f);

    glColor3f(0.0f, 0.8f, 0.0f);

    glBegin(GL_LINES);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.25f, 0.0f);

    glEnd();

    glPopMatrix();
}

void DebugShipRenderer::RenderBorder(Ship& ship)
{
    glColor3f(0.5f, 0.5f, 0.5f);

    glBegin(GL_LINES);

    glVertex3f(ship.Border.UpLeft.X, ship.Border.UpLeft.Y, ship.Border.UpLeft.Z);
    glVertex3f(ship.Border.UpRight.X, ship.Border.UpRight.Y, ship.Border.UpRight.Z);

    glVertex3f(ship.Border.UpRight.X, ship.Border.UpRight.Y, ship.Border.UpRight.Z);
    glVertex3f(ship.Border.DownRight.X, ship.Border.DownRight.Y, ship.Border.DownRight.Z);

    glVertex3f(ship.Border.DownRight.X, ship.Border.DownRight.Y, ship.Border.DownRight.Z);
    glVertex3f(ship.Border.DownLeft.X, ship.Border.DownLeft.Y, ship.Border.DownLeft.Z);

    glVertex3f(ship.Border.DownLeft.X, ship.Border.DownLeft.Y, ship.Border.DownLeft.Z);
    glVertex3f(ship.Border.UpLeft.X, ship.Border.UpLeft.Y, ship.Border.UpLeft.Z);

    glEnd();
}

float DebugShipRenderer::GetAngleBetweenShipAndYStraight(Ship& ship)
{
    Vector3d v(ship.FrontMiddlePoint);
    v.Sub(ship.RearMiddlePoint);
    v.Normalize();
    Vector3d straight(0.0f, 1.0f, 0.0f);
    float cosAlpha = v.DotProduct(straight);
    float alpha = Math::ArcCos(cosAlpha);
    if (v.X > 0.0f) alpha = -alpha;

    return alpha;
}
