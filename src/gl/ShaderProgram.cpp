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

void ShaderProgram::SetUniform(const char* name, float v1, float v2, float v3)
{
    glUniform3f(glGetUniformLocation(_programId, name), v1, v2, v3);
}

void ShaderProgram::SetUniform(const char* name, float v1, float v2, float v3, float v4)
{
    glUniform4f(glGetUniformLocation(_programId, name), v1, v2, v3, v4);
}

void ShaderProgram::SetUniform(const char* name, Vector3& v)
{
    glUniform3f(glGetUniformLocation(_programId, name), v.X, v.Y, v.Z);
}

void ShaderProgram::SetUniform(const char* name, Vector3& v, float v4)
{
    glUniform4f(glGetUniformLocation(_programId, name), v.X, v.Y, v.Z, v4);
}

void ShaderProgram::SetUniform(const char* name, const float* v)
{
    glUniformMatrix4fv(glGetUniformLocation(_programId, name), 1, GL_FALSE, v);
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
