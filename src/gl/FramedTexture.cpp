#include <gl/opengl.h>
#include <gl/ImageFile.h>
#include <gl/FramedTexture.h>

FramedTexture::FramedTexture()
{
    _frameWidth = 0;
    _frameHeight = 0;
    _framesCount = 0;
    _textureStep = 0.0f;
}

void FramedTexture::Load(String filePath, int framesCount)
{
    _texture.Load(filePath);
    _framesCount = framesCount;
    _textureStep = 1.0f / (float)_framesCount;
    ImageFile imageFile(filePath.GetWCharBuf());
    _frameWidth = (int)(imageFile.GetWidth() / framesCount);
    _frameHeight = imageFile.GetHeight();
}

void FramedTexture::RenderFrame(int frameIndex)
{
    glEnable(GL_TEXTURE_2D);
    _texture.Bind();
    glBegin(GL_QUADS);

    const float textureCoord = _textureStep * (float)frameIndex;

    glTexCoord2f(textureCoord, 0.0f);
    glVertex2i(0, 0);

    glTexCoord2f(textureCoord + _textureStep, 0.0f);
    glVertex2i(_frameWidth, 0);

    glTexCoord2f(textureCoord + _textureStep, 1.0f);
    glVertex2i(_frameWidth, _frameHeight);

    glTexCoord2f(textureCoord, 1.0f);
    glVertex2i(0, _frameHeight);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

int FramedTexture::GetFrameWidth()
{
    return _frameWidth;
}

int FramedTexture::GetFrameHeight()
{
    return _frameHeight;
}

int FramedTexture::GetFramesCount()
{
    return _framesCount;
}
