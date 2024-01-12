#include <gl/opengl.h>
#include <gl/Textures.h>
#include <render/release/BackgroundRenderer.h>

BackgroundRenderer::BackgroundRenderer() :
    _sphere(1000.0f, 8, 45)
{
    _textureWidthStep = 1.0f / 45.0f;
    _textureHeightStep = 0.5f / 8.0f;
}

void BackgroundRenderer::Init()
{
    _backgroundTexture.Load(Textures::GetBackgroundTextureFilePath());
}

void BackgroundRenderer::Render()
{
    glEnable(GL_TEXTURE_2D);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    _backgroundTexture.Bind();
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    for (int level = -_sphere.GetLevelsCount() + 2; level < _sphere.GetLevelsCount() - 2; level++)
    {
        for (int point = 0; point < _sphere.GetLevelPointsCount() - 1; point++)
        {
            RenderSphereSegment(level, point);
        }
        RenderSphereSegment(level, _sphere.GetLevelPointsCount() - 1);
    }
    glEnd();
    glDisable(GL_CULL_FACE);
    glDisable(GL_TEXTURE_2D);
}

void BackgroundRenderer::RenderSphereSegment(int level, int point)
{
    float textureX = _textureWidthStep * (float)point;
    float textureXNext = textureX + _textureWidthStep;
    float textureY = 0.5f + _textureHeightStep * (float)level;
    int nextPoint = point + 1;
    if (nextPoint == _sphere.GetLevelPointsCount())
    {
        nextPoint = 0;
        textureXNext = 1.0f;
    }

    glTexCoord2f(1.0f - textureX, textureY);
    glVertex3f(_sphere.GetPoint(level, point));

    glTexCoord2f(1.0f - textureX, textureY + _textureHeightStep);
    glVertex3f(_sphere.GetPoint(level + 1, point));

    glTexCoord2f(1.0f - textureXNext, textureY + _textureHeightStep);
    glVertex3f(_sphere.GetPoint(level + 1, nextPoint));

    glTexCoord2f(1.0f - textureXNext, textureY);
    glVertex3f(_sphere.GetPoint(level, nextPoint));
}
