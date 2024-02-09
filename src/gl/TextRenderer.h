#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/Array.h>
#include <gl/Texture.h>

class TextRenderer : public Object
{
    Texture _alphTexture;
    Array<float, 256> _textureCoords;
    float _textureStep;
    float _letterWidth;
    float _letterHeight;

public:
    TextRenderer();

    void Init();
    void Render(String& text);
    float GetLetterWidth();
    float GetLetterHeight();
};
