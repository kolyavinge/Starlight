#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>
#include <lib/List.h>
#include <calc/Vector3.h>

class ShaderProgramException : public Exception { };

enum class ShaderKind { Vertex, Fragment };

class ShaderProgram : public Object
{
    unsigned int _programId;
    List<unsigned int> _shadersId;

public:
    ShaderProgram();
    ~ShaderProgram() override;

    void LoadShader(ShaderKind kind, String filePath);
    void Use();
    void Unuse();
    void SetUniform(const char* name, float v);
    void SetUniform(const char* name, float v1, float v2, float v3);
    void SetUniform(const char* name, float v1, float v2, float v3, float v4);
    void SetUniform(const char* name, Vector3& v);
    void SetUniform(const char* name, Vector3& v, float v4);
    void SetUniform(const char* name, const float* v);

private:
    void CompileShader(unsigned int shaderId);
};
