#include <anx/GraphicResources.h>
#include <render/shader/ShaderPrograms.h>

ShaderPrograms::ShaderPrograms()
{
    DefaultShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetDefaultVertexShaderPath());
    DefaultShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetDefaultFragmentShaderPath());
    ExhaustShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetExhaustVertexShaderPath());
    ExhaustShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetExhaustFragmentShaderPath());
}

ShaderPrograms* ShaderProgramsResolvingFactory::Make(Resolver&)
{
    return new ShaderPrograms();
}
