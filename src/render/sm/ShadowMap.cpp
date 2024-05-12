#include <gl/opengl.h>
#include <render/sm/ShadowMap.h>

ShadowMap::ShadowMap()
{
    FBOId = 0;
    TextureId = 0;
}

ShadowMap::~ShadowMap()
{
    glDeleteTextures(1, &TextureId);
    glDeleteFramebuffers(1, &FBOId);
}
