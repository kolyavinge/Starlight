#include <gl/opengl.h>
#include <anx/GraphicResources.h>
#include <render/common/BackgroundRenderer.h>

BackgroundRenderer::BackgroundRenderer() :
    _textureWidthStep(1.0f / (float)_sphere.LevelPointsCount),
    _textureHeightStep(0.5f / (float)_sphere.LevelsCount)
{
}

void BackgroundRenderer::Init()
{
    _backgroundTexture.Load(GraphicResources::GetBackgroundTextureFilePath());
}

void BackgroundRenderer::Render()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
    _backgroundTexture.Bind();
    glBegin(GL_QUADS);
    for (int level = -_sphere.GetLevelsCount(); level < _sphere.GetLevelsCount(); level++)
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

BackgroundRenderer* BackgroundRendererResolvingFactory::Make(Resolver&)
{
    return new BackgroundRenderer();
}
