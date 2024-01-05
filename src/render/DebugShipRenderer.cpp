#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <model/ShipMeasure.h>
#include <core/GameConstants.h>
#include <render/DebugShipRenderer.h>

void DebugShipRenderer::Render(Ship& ship, Track& track)
{
    RenderMiddleLine(ship);
    RenderBorder(ship);
    RenderBorderPoints(ship);
    RenderTurnAngle(ship);
    RenderDeviation(ship);
    //RenderTrackPoints(ship, track);
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

void DebugShipRenderer::RenderDeviation(Ship& ship)
{
    glLineWidth(2.0f);
    glPushMatrix();

    glTranslatef(ship.CentralLine.Rear);

    glColor3f(0.5f, 0.0f, 0.0f);

    glBegin(GL_LINES);

    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(ship.Deviation);

    glEnd();

    glPopMatrix();
    glLineWidth(GameConstants::RenderLineWidth);
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

void DebugShipRenderer::RenderTrackPoints(Ship& ship, Track& track)
{
    glBegin(GL_LINES);

    glColor3f(0.5f, 0.6f, 0.5f);

    glVertex3f(track.InsidePoints[ship.CentralLine.TrackPointIndexFront]);
    glVertex3f(track.OutsidePoints[ship.CentralLine.TrackPointIndexFront]);

    glColor3f(0.5f, 0.5f, 0.6f);

    glVertex3f(track.InsidePoints[ship.CentralLine.TrackPointIndexRear]);
    glVertex3f(track.OutsidePoints[ship.CentralLine.TrackPointIndexRear]);

    glEnd();
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
