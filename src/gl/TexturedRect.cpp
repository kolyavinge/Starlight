#include <gl/opengl.h>
#include <gl/TexturedRect.h>

TexturedRect::TexturedRect()
{
    _width = 0.0f;
    _height = 0.0f;
}

void TexturedRect::Load(String filePath, float width, float height)
{
    _texture.Load(filePath);
    _width = width;
    _height = height;
}

void TexturedRect::Render()
{
    glEnable(GL_TEXTURE_2D);
    _texture.Bind();
    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(_width, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(_width, _height);

    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(0.0f, _height);

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

float TexturedRect::GetWidth()
{
    return _width;
}

float TexturedRect::GetHeight()
{
    return _height;
}
