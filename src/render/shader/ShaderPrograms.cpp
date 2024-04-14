#include <anx/GraphicResources.h>
#include <render/shader/ShaderPrograms.h>

ShaderPrograms::ShaderPrograms()
{
    DefaultShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetDefaultVertexShaderPath());
    DefaultShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetDefaultFragmentShaderPath());
}

ShaderPrograms* ShaderProgramsResolvingFactory::Make(Resolver&)
{
    return new ShaderPrograms();
}
