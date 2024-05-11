#include <lib/Assert.h>
#include <calc/Geometry.h>
#include <calc/Matrix4.h>
#include <model/ShipMeasure.h>
#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/ShipRenderer.h>

ShipRenderer::ShipRenderer(
    Camera& camera,
    ShipMesh& shipMesh,
    ExhaustRenderer& exhaustRenderer,
    ShaderPrograms& shaderPrograms,
    ShadowMaps& shadowMaps) :
    _camera(camera),
    _shipMesh(shipMesh),
    _exhaustRenderer(exhaustRenderer),
    _mainProgram(shaderPrograms.MainWithoutShadowsShaderProgram),
    _vertexOnlyProgram(shaderPrograms.VertexOnlyShaderProgram),
    _shadowMaps(shadowMaps),
    _vboMeshRenderer()
{
    _vboMeshRenderer.Init(shipMesh.GetMesh());
}

void ShipRenderer::Update()
{
    _exhaustRenderer.Update();
}

void ShipRenderer::Render(Ship& ship, int textureIndex)
{
    bool renderShipEnabled;
    bool renderExhaustEnabled;
    GetRenderDetails(ship, renderShipEnabled, renderExhaustEnabled, textureIndex);

    if (renderShipEnabled)
    {
        Matrix4 modelMatrix;
        ship.GetModelMatrix(modelMatrix);
        _mainProgram.Use();
        _mainProgram.SetUniform("lightPos", RenderConstants::GlobalLightPosition);
        _mainProgram.SetUniform("cameraPos", _camera.Position);
        _mainProgram.SetUniform("modelMatrix", modelMatrix.GetPtr());
        _mainProgram.SetUniform("alpha", 1.0f);
        _mainProgram.SetUniform("shadowMatrix1", _shadowMaps.ShipShadowMaps[0].ShadowMatrix.GetPtr());
        _mainProgram.SetUniform("shadowMatrix2", _shadowMaps.ShipShadowMaps[1].ShadowMatrix.GetPtr());
        _mainProgram.SetUniform("shadowMatrix3", _shadowMaps.ShipShadowMaps[2].ShadowMatrix.GetPtr());
        _mainProgram.SetUniform("shadowMatrix4", _shadowMaps.ShipShadowMaps[3].ShadowMatrix.GetPtr());

        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[0].TextureId);
        glActiveTexture(GL_TEXTURE2);
        glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[1].TextureId);
        glActiveTexture(GL_TEXTURE3);
        glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[2].TextureId);
        glActiveTexture(GL_TEXTURE4);
        glBindTexture(GL_TEXTURE_2D, _shadowMaps.ShipShadowMaps[3].TextureId);

        glPushMatrix();
        glEnable(GL_DEPTH_TEST);
        SetPosition(ship);
        _vboMeshRenderer.SetActiveTextureIndex(textureIndex);
        _vboMeshRenderer.Render();
        _mainProgram.Unuse();
    }

    if (renderExhaustEnabled)
    {
        RenderExhaust(ship);
    }

    glDisable(GL_DEPTH_TEST);
    glPopMatrix();
}

void ShipRenderer::FillDepthBufferForShadow(Ship& ship)
{
    bool renderShipEnabled;
    bool renderExhaustEnabled;
    int textureIndex;
    GetRenderDetails(ship, renderShipEnabled, renderExhaustEnabled, textureIndex);
    if (renderShipEnabled)
    {
        glPushMatrix();
        glEnable(GL_DEPTH_TEST);
        SetPosition(ship);
        _vertexOnlyProgram.Use();
        _vboMeshRenderer.Render();
        _vertexOnlyProgram.Unuse();
        glDisable(GL_DEPTH_TEST);
        glPopMatrix();
    }
}

void ShipRenderer::RenderExhaust(Ship& ship)
{
    glPushMatrix();
    glTranslatef(-0.32f, 0.16f, 0.15f);
    glRotatef(-0.8f, Constants::UpAxis);
    _exhaustRenderer.Render(ship);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.325f, 0.16f, 0.15f);
    glRotatef(0.9f, Constants::UpAxis);
    _exhaustRenderer.Render(ship);
    glPopMatrix();
}

void ShipRenderer::GetRenderDetails(Ship& ship, bool& renderShipEnabled, bool& renderExhaustEnabled, int& textureIndex)
{
    renderShipEnabled = false;
    renderExhaustEnabled = false;
    if (ship.State == ShipState::Active)
    {
        renderShipEnabled = true;
        renderExhaustEnabled = true;
    }
    else if (ship.State == ShipState::Exploded || ship.State == ShipState::Destroyed)
    {
        textureIndex = ShipMesh::DestroyedTexture;
        renderShipEnabled = true;
    }
    else if (ship.State == ShipState::Reseted || ship.State == ShipState::Prepared)
    {
        if ((ship.DelayIterations % 10) == 0) // мерцание кораблика
        {
            renderShipEnabled = true;
            renderExhaustEnabled = true;
        }
    }
    else
    {
        Assert::Fail();
    }
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
        resolver.Resolve<ExhaustRenderer>(),
        resolver.Resolve<ShaderPrograms>(),
        resolver.Resolve<ShadowMaps>());
}
