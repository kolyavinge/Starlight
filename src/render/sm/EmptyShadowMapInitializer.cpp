#include <gl/opengl.h>
#include <render/sm/EmptyShadowMapInitializer.h>

EmptyShadowMapInitializer::EmptyShadowMapInitializer(
    ShadowMaps& shadowMaps,
    ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator) :
    _emptyShadowMap(shadowMaps.EmptyShadowMap)
{
    shadowMapFramebufferGenerator.Generate(1, 1, _emptyShadowMap.FBOId, _emptyShadowMap.TextureId);
}

void EmptyShadowMapInitializer::Init()
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glBindFramebuffer(GL_FRAMEBUFFER, _emptyShadowMap.FBOId);
    glViewport(0, 0, 1, 1);
    glClear(GL_DEPTH_BUFFER_BIT);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

EmptyShadowMapInitializer* EmptyShadowMapInitializerResolvingFactory::Make(Resolver& resolver)
{
    return new EmptyShadowMapInitializer(
        resolver.Resolve<ShadowMaps>(),
        resolver.Resolve<ShadowMapFramebufferGenerator>());
}
