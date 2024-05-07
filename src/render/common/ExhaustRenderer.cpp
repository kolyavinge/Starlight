#include <lib/Math.h>
#include <gl/opengl.h>
#include <render/common/ExhaustRenderer.h>

ExhaustRenderer::ExhaustRenderer(
    ExhaustMesh& exhaustMesh,
    ShaderPrograms& shaderPrograms) :
    _exhaustMesh(exhaustMesh),
    _shaderProgram(shaderPrograms.ExhaustShaderProgram)
{
    _activeTextureIndex = 0;
    _vboMeshRenderer.Init(_exhaustMesh.GetMesh());
}

void ExhaustRenderer::Update()
{
    _activeTextureIndex++;
    if (_activeTextureIndex == _exhaustMesh.GetMesh().Textures.GetCount())
    {
        _activeTextureIndex = 0;
    }
}

void ExhaustRenderer::Render(Ship& ship)
{
    const float velocityRate = ship.VelocityValue / ship.VelocityFunction.InitMaxVelocity;
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    RenderNoozle(velocityRate);
    RenderFlame(velocityRate);
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);
}

void ExhaustRenderer::RenderNoozle(float velocityRate)
{
    NormalizedRGB tempColor = _colorTemperatureFunc.GetColor(Math::Min(velocityRate, 1.0f));
    glColor4f(tempColor.R, tempColor.G, tempColor.B, 0.5f);
    glBegin(GL_POLYGON);
    for (int pointIndex = 0; pointIndex < ExhaustMesh::CirclePointsCount; pointIndex++)
    {
        glVertex3f(_exhaustMesh.FromRadiusPoints[pointIndex]);
    }
    glEnd();
}

void ExhaustRenderer::RenderFlame(float velocityRate)
{
    const float lengthRate = Math::Max(velocityRate, 0.3f);
    _shaderProgram.Use();
    _shaderProgram.SetUniform("lengthRate", lengthRate);
    _vboMeshRenderer.SetActiveTextureIndex(_activeTextureIndex);
    _vboMeshRenderer.Render();
    _shaderProgram.Unuse();
}

ExhaustRenderer* ExhaustMeshRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ExhaustRenderer(
        resolver.Resolve<ExhaustMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
