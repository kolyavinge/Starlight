#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>

class TextureLoadException : public Exception { };

class Texture : public Object
{
    unsigned int _textureId;

public:
    Texture();
    ~Texture();

    void Load(String filePath);
    void Bind();
};
