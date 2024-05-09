#include <calc/Vector3.h>
#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/sm/ShipShadowMapUpdater.h>

ShipShadowMapUpdater::ShipShadowMapUpdater(
    Race& race,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    ShadowMaps& shadowMaps) :
    _resolutionWidth(500),
    _resolutionHeight(500),
    _race(race),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _shipShadowMap(shadowMaps.ShipShadowMap)
{
    InitFBO();
}

void ShipShadowMapUpdater::Update()
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glPushMatrix();
    glBindFramebuffer(GL_FRAMEBUFFER, _fboId);

    glViewport(0, 0, _resolutionWidth, _resolutionHeight);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    Vector3 upAxis(0.0f, 1.0f, 0.0f);
    gluLookAt(RenderConstants::GlobalLightPosition, _race.Player.CentralLine.Front, upAxis);

    _trackRenderer.Render();
    _shipsRenderer.RenderShip(_race.Player, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glPopMatrix();
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void ShipShadowMapUpdater::InitFBO()
{
    glGenTextures(1, &_shipShadowMap.TextureId);
    glBindTexture(GL_TEXTURE_2D, _shipShadowMap.TextureId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH_COMPONENT24, _resolutionWidth, _resolutionHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 0.0f, 0.0f, 0.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LESS);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _shipShadowMap.TextureId);
    glGenFramebuffers(1, &_fboId);
    glBindFramebuffer(GL_FRAMEBUFFER, _fboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _shipShadowMap.TextureId, 0);
    GLenum drawBuffers[] = { GL_NONE };
    glDrawBuffers(1, drawBuffers);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

ShipShadowMapUpdater* ShipShadowMapUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new ShipShadowMapUpdater(
        resolver.Resolve<Race>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<ShadowMaps>());
}
