#pragma once

#include <lib/Object.h>

class Texture : public Object
{
    unsigned int _textureId;

public:
    Texture();

    void Load(const wchar_t* fileName);
    void Bind();
};
