#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <gl/Texture.h>

class TexturedRect : public Object
{
    Texture _texture;
    float _width;
    float _height;

public:
    TexturedRect();

    void Load(String filePath, float width, float height);
    void Render();
    float GetWidth();
    float GetHeight();
};
