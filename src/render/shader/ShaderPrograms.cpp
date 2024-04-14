#include <anx/GraphicResources.h>
#include <render/shader/ShaderPrograms.h>

ShaderPrograms::ShaderPrograms()
{
    DefaultShaderProgram.LoadShader(ShaderKind::Vertex, GraphicResources::GetSimpleVertexShaderPath());
    DefaultShaderProgram.LoadShader(ShaderKind::Fragment, GraphicResources::GetSimpleFragmentShaderPath());
}

ShaderPrograms* ShaderProgramsResolvingFactory::Make(Resolver&)
{
    return new ShaderPrograms();
}
