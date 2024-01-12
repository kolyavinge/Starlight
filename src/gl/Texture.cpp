#include <gl/opengl.h>
#include <soil/SOIL.h>
#include <lib/File.h>
#include <gl/Texture.h>

Texture::Texture()
{
    _textureId = 0;
}

Texture::~Texture()
{
    glDeleteTextures(1, &_textureId);
}

void Texture::Load(String filePath)
{
    File::ErrorIfFileNotFound(filePath.GetWCharBuf());
    _textureId = SOIL_load_OGL_texture
    (
        filePath.GetCharBuf(),
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_INVERT_Y
    );
    if (_textureId == 0) throw TextureLoadException();
}

void Texture::Bind()
{
    glBindTexture(GL_TEXTURE_2D, _textureId);
}
