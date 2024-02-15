#include <gl/opengl.h>
#include <lib/Math.h>
#include <core/Constants.h>
#include <gl/ImageFile.h>
#include <anx/GraphicResources.h>
#include <render/common/RenderConstants.h>
#include <render/common/FinishRenderer.h>

FinishRenderer::FinishRenderer()
{
    _zCoords.InitZero();
    _phase = 0.0f;
    _width = 0.0f;
    _height = 0.0f;
    _radiansStep = Math::PiDouble / (float)_zCoords.Count;
    _widthStep = 0.0f;
    _textureStep = 1.0f / (float)_zCoords.Count;
}

void FinishRenderer::Init()
{
    _finishTexture.Load(GraphicResources::GetFinishItemFilePath());
    ImageFile image(GraphicResources::GetFinishItemFilePath().GetWCharBuf());
    _width = (float)image.GetWidth();
    _height = (float)image.GetHeight();
    _widthStep = _width / (float)_zCoords.Count;
}

void FinishRenderer::Render()
{
    glPushMatrix();
    glTranslatef(
        (Constants::ScreenWidth - _width) / 2.0f,
        (Constants::ScreenHeight - _height) / 2.0f,
        0.0f);
    glRotatef(5.0f, 1.0f, 0.0f, 0.0f);
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glEnable(GL_TEXTURE_2D);
    _finishTexture.Bind();
    glBegin(GL_QUADS);
    for (int i = 0; i < _zCoords.Count; i++)
    {
        float z = _zCoords[i];
        float x = (float)i * _widthStep;
        float texX = (float)i * _textureStep;

        glTexCoord2f(texX, 0.0f);
        glVertex3f(x, 0.0f, z);

        glTexCoord2f(texX + _textureStep, 0.0f);
        glVertex3f(x + _widthStep, 0.0f, z);

        glTexCoord2f(texX + _textureStep, 1.0f);
        glVertex3f(x + _widthStep, _height, z);

        glTexCoord2f(texX, 1.0f);
        glVertex3f(x, _height, z);
    }
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();
    UpdateZCoords();
}

float FinishRenderer::GetWidth()
{
    return _width;
}

float FinishRenderer::GetHeight()
{
    return _height;
}

void FinishRenderer::UpdateZCoords()
{
    for (int i = 0; i < _zCoords.Count; i++)
    {
        _zCoords[i] = 40.0f * Math::Sin((float)i * _radiansStep + _phase);
    }
    _phase -= 0.15f;
}
