#include <gl/opengl.h>
#include <gl/ImageFile.h>
#include <gl/TexturedRect.h>

TexturedRect::TexturedRect()
{
    _width = 0;
    _height = 0;
}

void TexturedRect::Load(String filePath)
{
    _texture.Load(filePath);
    ImageFile image(filePath.GetWCharBuf());
    _width = image.GetWidth();
    _height = image.GetHeight();
}

void TexturedRect::Render()
{
    glEnable(GL_TEXTURE_2D);
    _texture.Bind();
    glBegin(GL_QUADS);

    glTexCoord2i(0, 0);
    glVertex2i(0, 0);

    glTexCoord2i(1, 0);
    glVertex2i(_width, 0);

    glTexCoord2i(1, 1);
    glVertex2i(_width, _height);

    glTexCoord2i(0, 1);
    glVertex2i(0, _height);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

int TexturedRect::GetWidth()
{
    return _width;
}

int TexturedRect::GetHeight()
{
    return _height;
}
