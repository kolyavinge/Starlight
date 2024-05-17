#include <anx/GraphicResources.h>
#include <render/shader/ShaderPrograms.h>

ShaderPrograms::ShaderPrograms()
{
    ExhaustShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetExhaustVertexShaderPath());
    ExhaustShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetExhaustFragmentShaderPath());

    MeshShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetMeshVertexShaderPath());
    MeshShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetMeshFragmentShaderPath());

    MainShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetMainVertexShaderPath());
    MainShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetMainFragmentShaderPath());

    VertexOnlyShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetVertexOnlyVertexShaderPath());
}

ShaderPrograms* ShaderProgramsResolvingFactory::Make(Resolver&)
{
    return new ShaderPrograms();
}
