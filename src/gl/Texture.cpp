#include <gl/opengl.h>
#include <soil/SOIL.h>
#include <lib/File.h>
#include <gl/Texture.h>

Texture::Texture()
{
    _textureId = 0;
}

Texture::Texture(String filePath)
{
    _textureId = 0;
    Load(filePath);
}

Texture::~Texture()
{
    if (IsLoaded())
    {
        glDeleteTextures(1, &_textureId);
    }
}

void Texture::Load(String filePath)
{
    if (IsLoaded()) throw TextureLoadException();
    File::ErrorIfFileNotFound(filePath.GetWCharBuf());
    _textureId = SOIL_load_OGL_texture
    (
        filePath.GetCharBuf(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (!IsLoaded()) throw TextureLoadException();
}

bool Texture::IsLoaded()
{
    return _textureId != 0;
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, _textureId);
}
