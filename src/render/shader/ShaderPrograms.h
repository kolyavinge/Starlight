#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/ShaderProgram.h>

class ShaderPrograms : public Object
{
public:
    ShaderProgram DefaultShaderProgram;
    ShaderProgram ExhaustShaderProgram;

    ShaderPrograms();
};

class ShaderProgramsResolvingFactory : public ResolvingFactory<ShaderPrograms>
{
public:
    ShaderPrograms* Make(Resolver& resolver);
};
