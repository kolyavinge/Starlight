#include "gl/opengl.h"
#include "lib/Math.h"
#include "calc/Geometry.h"
#include "render/DebugShipRenderer.h"

void DebugShipRenderer::Render(Ship& ship)
{
    RenderMiddleLine(ship);
    RenderMiddlePoints(ship);
    RenderTurnAngle(ship);
}

void DebugShipRenderer::RenderMiddleLine(Ship& ship)
{
    glBegin(GL_LINES);

    glColor3f(0.5f, 0.5f, 0.5f);
    glVertex3f(ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y, ship.FrontMiddlePoint.Z);
    glVertex3f(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y, ship.RearMiddlePoint.Z);

    glEnd();
}

void DebugShipRenderer::RenderMiddlePoints(Ship& ship)
{
    glBegin(GL_POINTS);

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(ship.FrontMiddlePoint.X, ship.FrontMiddlePoint.Y, ship.FrontMiddlePoint.Z);

    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y, ship.RearMiddlePoint.Z);

    glEnd();
}

void DebugShipRenderer::RenderTurnAngle(Ship& ship)
{
    float angleBetween = GetAngleBetweenShipAndYStraight(ship);

    glPushMatrix();

    glTranslatef(ship.RearMiddlePoint.X, ship.RearMiddlePoint.Y, ship.RearMiddlePoint.Z);
    glRotatef(Geometry::RadiansToDegrees(angleBetween + ship.TurnAngleRadians), 0.0f, 0.0f, 1.0f);

    glBegin(GL_LINES);

    glColor3f(0.0f, 0.8f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.25f, 0.0f);

    glEnd();

    glPopMatrix();
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
