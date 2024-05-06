#include <glew/glew.h>
#include <gl/opengl.h>
#include <lib/Math.h>
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
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);

    _shaderProgram.Use();
    float lengthRate = Math::Max(ship.VelocityValue / ship.VelocityFunction.InitMaxVelocity, 0.3f);
    _shaderProgram.SetUniform("lengthRate", lengthRate);
    _vboMeshRenderer.SetActiveTextureIndex(_activeTextureIndex);
    _vboMeshRenderer.Render();
    _shaderProgram.Unuse();

    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);
}

ExhaustRenderer* ExhaustMeshRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ExhaustRenderer(
        resolver.Resolve<ExhaustMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
