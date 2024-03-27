#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Texture.h>

class FramedTexture : public Object
{
    Texture _texture;
    int _frameWidth;
    int _frameHeight;
    int _framesCount;
    float _textureStep;

public:
    FramedTexture();

    void Load(String filePath, int framesCount);
    void RenderFrame(int frameIndex);
    int GetFrameWidth();
    int GetFrameHeight();
    int GetFramesCount();
};

class FramedTextureResolvingFactory : public ResolvingFactory<FramedTexture>
{
public:
    FramedTexture* Make(Resolver& resolver) override;
};
