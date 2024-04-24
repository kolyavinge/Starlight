#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <gl/Texture.h>
#include <gl/ITexturedRect.h>

class TexturedRect : public Object, public ITexturedRect
{
    Texture _texture;
    int _width;
    int _height;

public:
    TexturedRect();

    void Load(String filePath);
    void Render() override;
    int GetWidth() override;
    int GetHeight() override;
};
