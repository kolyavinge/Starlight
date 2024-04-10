#include <gl/opengl.h>
#include <render/common/ShipRenderer.h>

ShipRenderer::ShipRenderer(ShipMesh& shipMesh) :
    _shipMesh(shipMesh)
{
}

void ShipRenderer::Render(Ship& ship, int textureIndex)
{
    _shipMesh.Render(ship, textureIndex);
    //RenderAIMovingDirections(ship);
    //RenderThrottle(ship);
}

void ShipRenderer::RenderAIMovingDirections(Ship& ship)
{
    for (int i = 0; i < ship.AIData.MovingDirections.AvailableDirections.GetCount(); i++)
    {
        if (ship.AIData.MovingDirections.EnabledDirections[i])
        {
            glColor3f(0.0f, 0.5f, 0.0f);
        }
        else
        {
            glColor3f(0.5f, 0.0f, 0.0f);
        }
        glBegin(GL_LINES);
        glVertex3f(
            ship.CentralLine.Front.X,
            ship.CentralLine.Front.Y,
            ship.CentralLine.Front.Z);
        glVertex3f(
            ship.CentralLine.Front.X + ship.AIData.MovingDirections.AvailableDirections[i].X,
            ship.CentralLine.Front.Y + ship.AIData.MovingDirections.AvailableDirections[i].Y,
            ship.CentralLine.Front.Z + ship.AIData.MovingDirections.AvailableDirections[i].Z);
        glEnd();
    }
    glColor3f(0.5f, 0.5f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(
        ship.CentralLine.Front.X,
        ship.CentralLine.Front.Y,
        ship.CentralLine.Front.Z);
    glVertex3f(
        ship.CentralLine.Front.X + 5.0f * ship.AIData.MovingDirections.ResultDirection.X,
        ship.CentralLine.Front.Y + 5.0f * ship.AIData.MovingDirections.ResultDirection.Y,
        ship.CentralLine.Front.Z + 5.0f * ship.AIData.MovingDirections.ResultDirection.Z);
    glEnd();
}

void ShipRenderer::RenderThrottle(Ship& ship)
{
    if (ship.Controls.IsThrottleActive)
    {
        glColor3f(0.0f, 0.5f, 0.0f);
    }
    else
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    glPushMatrix();
    glTranslatef(ship.Border.DownRight);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.0f, 0.0f);
    glVertex3f(0.1f, 0.1f, 0.0f);
    glVertex3f(0.0f, 0.1f, 0.0f);
    glEnd();
    glPopMatrix();
}

ShipRenderer* ShipRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipRenderer(resolver.Resolve<ShipMesh>());
}
