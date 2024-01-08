#include <gl/opengl.h>
#include <lib/Memory.h>
#include <gl/ImageFile.h>
#include <gl/Texture.h>

Texture::Texture()
{
    _textureId = 0;
}

void Texture::Load(const wchar_t* fileName)
{
    ImageFile image(fileName);
    unsigned char* textureData = (unsigned char*)Memory::Alloc(4 * (sizeof(unsigned char)) * image.GetWidth() * image.GetHeight());
    int k = 0;
    PixelData pixelData;
    for (int h = image.GetHeight() - 1; h >= 0; h--)
    {
        for (int w = 0; w < image.GetWidth(); w++)
        {
            image.GetPixelData(w, h, pixelData);
            textureData[k++] = pixelData.R;
            textureData[k++] = pixelData.G;
            textureData[k++] = pixelData.B;
            textureData[k++] = 255;
        }
    }
    glGenTextures(1, &_textureId);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.GetWidth(), image.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, textureData);
    Memory::Release(textureData);
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, _textureId);
}
