#include <gl/opengl.h>
#include <gl/ShadowedTexturedRect.h>

ShadowedTexturedRect::ShadowedTexturedRect(ITexturedRect& texturedRect) :
    _texturedRect(texturedRect)
{
}

void ShadowedTexturedRect::Render()
{
    float color[4];
    glGetFloatv(GL_CURRENT_COLOR, color);

    glColor3f(0.0f, 0.0f, 0.0f);

    glPushMatrix();
    glTranslatef(4.0f, -4.0f, 0.0f);
    _texturedRect.Render();
    glPopMatrix();

    glColor3fv(color);
    _texturedRect.Render();
}

int ShadowedTexturedRect::GetWidth()
{
    return _texturedRect.GetWidth();
}

int ShadowedTexturedRect::GetHeight()
{
    return _texturedRect.GetHeight();
}
