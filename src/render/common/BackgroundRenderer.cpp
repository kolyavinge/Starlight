#include <render/common/BackgroundRenderer.h>

BackgroundRenderer::BackgroundRenderer(
    BackgroundSphereMesh& backgroundSphereMesh,
    ShaderPrograms& shaderPrograms) :
    _shaderProgram(shaderPrograms.MeshShaderProgram)
{
    _vboMeshRenderer.Init(backgroundSphereMesh.GetMesh());
}

void BackgroundRenderer::Render()
{
    _shaderProgram.Use();
    _vboMeshRenderer.Render();
    _shaderProgram.Unuse();
}

BackgroundRenderer* BackgroundRendererResolvingFactory::Make(Resolver& resolver)
{
    return new BackgroundRenderer(
        resolver.Resolve<BackgroundSphereMesh>(),
        resolver.Resolve<ShaderPrograms>());
}
