#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <gl/Texture.h>

class TexturedRect : public Object
{
    Texture _texture;
    int _width;
    int _height;

public:
    TexturedRect();

    void Load(String filePath);
    void Render();
    int GetWidth();
    int GetHeight();
};
