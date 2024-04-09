#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>
#include <lib/List.h>

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

private:
    void CompileShader(unsigned int shaderId);
};
