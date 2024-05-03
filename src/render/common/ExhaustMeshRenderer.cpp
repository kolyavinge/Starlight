#include <gl/opengl.h>
#include <render/common/ExhaustMeshRenderer.h>

ExhaustMeshRenderer::ExhaustMeshRenderer(
    ExhaustMesh& exhaustMesh,
    ShaderPrograms& shaderPrograms) :
    _exhaustMesh(exhaustMesh),
    _shaderProgram(shaderPrograms.ExhaustShaderProgram)
{
    _activeTextureIndex = 0;
    _vboMeshRenderer.Init(_exhaustMesh.GetMesh());
}

void ExhaustMeshRenderer::Update()
{
    _activeTextureIndex++;
    if (_activeTextureIndex == _exhaustMesh.GetMesh().Textures.GetCount())
    {
        _activeTextureIndex = 0;
    }
}

void ExhaustMeshRenderer::Render()
{
    glEnable(GL_BLEND);
    _shaderProgram.Use();
    _vboMeshRenderer.SetActiveTextureIndex(_activeTextureIndex);
    _vboMeshRenderer.Render();
    _shaderProgram.Unuse();
    glDisable(GL_BLEND);
}

ExhaustMeshRenderer* ExhaustMeshRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ExhaustMeshRenderer(
        resolver.Resolve<ExhaustMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
