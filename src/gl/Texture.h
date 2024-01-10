#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class Texture : public Object
{
    unsigned int _textureId;

public:
    Texture();
    ~Texture();

    void Load(String filePath);
    void Bind();
};
