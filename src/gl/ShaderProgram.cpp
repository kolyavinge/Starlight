#include <glew/glew.h>
#include <lib/File.h>
#include <gl/ShaderProgram.h>

ShaderProgram::ShaderProgram()
{
    _programId = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
    Unuse();
    for (int i = 0; i < _shadersId.GetCount(); i++)
    {
        glDetachShader(_programId, _shadersId[i]);
        glDeleteShader(_shadersId[i]);
    }
    glDeleteProgram(_programId);
}

void ShaderProgram::LoadShader(ShaderKind kind, String filePath)
{
    const int maxLength = 10 * 1024;
    char shaderSourceCode[maxLength] = {};
    File::ReadAllBytes(filePath.GetWCharBuf(), maxLength, shaderSourceCode);
    unsigned int shaderId = glCreateShader(kind == ShaderKind::Vertex ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    const GLchar* ssc = shaderSourceCode;
    glShaderSource(shaderId, 1, &ssc, 0);
    CompileShader(shaderId);
    _shadersId.Add(shaderId);
    glAttachShader(_programId, shaderId);
    glLinkProgram(_programId);
}

void ShaderProgram::Use()
{
    glUseProgram(_programId);
}

void ShaderProgram::Unuse()
{
    glUseProgram(0);
}

void ShaderProgram::CompileShader(unsigned int shaderId)
{
    glCompileShader(shaderId);
    GLint isCompiled = 0;
    glGetShaderiv(shaderId, GL_COMPILE_STATUS, &isCompiled);
    if (isCompiled == GL_FALSE)
    {
        GLint maxLength = 512;
        GLchar errorBuf[512] = {};
        glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &maxLength);
        glGetShaderInfoLog(shaderId, maxLength, &maxLength, errorBuf);
        glDeleteShader(shaderId);
        throw ShaderProgramException();
    }
}
