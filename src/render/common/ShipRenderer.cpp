#include <gl/opengl.h>
#include <calc/Geometry.h>
#include <calc/ModelMatrix.h>
#include <model/ShipMeasure.h>
#include <render/common/RenderConstants.h>
#include <render/common/ShipRenderer.h>

ShipRenderer::ShipRenderer(
    Camera& camera,
    ShipMesh& shipMesh,
    ShaderPrograms& shaderPrograms) :
    _camera(camera),
    _shipMesh(shipMesh),
    _shaderProgram(shaderPrograms.DefaultShaderProgram),
    _vboMeshRenderer()
{
    _vboMeshRenderer.Init(shipMesh.GetMesh());
}

void ShipRenderer::Render(Ship& ship, int textureIndex)
{
    ModelMatrix modelMatrix;
    ship.GetModelMatrix(modelMatrix);

    _shaderProgram.Use();
    _shaderProgram.SetUniform("lightPos", RenderConstants::LightPosition);
    _shaderProgram.SetUniform("cameraPos", _camera.Position);
    _shaderProgram.SetUniform("modelMatrix", modelMatrix.GetPtr());
    _shaderProgram.SetUniform("alpha", 1.0f);
    _vboMeshRenderer.SetActiveTextureIndex(textureIndex);

    glPushMatrix();
    SetPosition(ship);
    _vboMeshRenderer.Render();
    //RenderAIMovingDirections(ship);
    //RenderThrottle(ship);
    glPopMatrix();

    _shaderProgram.Unuse();
}

void ShipRenderer::SetPosition(Ship& ship)
{
    float radians;
    Vector3 pivot;
    ship.Border.GetAngleAndPivot(radians, pivot);
    glTranslatef(ship.Border.DownLeft);
    glRotatef(Geometry::RadiansToDegrees(radians), pivot);
    glTranslatef(ShipMeasure::XLengthHalf, 0.0f, 0.0f);
    glRotatef(Geometry::RadiansToDegrees(ship.GetRollRadians()), 0.0f, 1.0f, 0.0f);
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
    return new ShipRenderer(
        resolver.Resolve<Camera>(),
        resolver.Resolve<ShipMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
