#include <lib/Assert.h>
#include <lib/Math.h>
#include <calc/Vector3.h>
#include <model/ShipMeasure.h>
#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/sm/ShipShadowMapUpdater.h>

ShipShadowMapUpdater::ShipShadowMapUpdater(
    Race& race,
    ShipsRenderer& shipsRenderer,
    ShadowMaps& shadowMaps) :
    _resolutionWidth(2000),
    _resolutionHeight(2000),
    _race(race),
    _shipsRenderer(shipsRenderer),
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
    gluPerspective(90.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    Vector3 lightPosition(RenderConstants::GlobalLightPosition);
    lightPosition.Sub(_race.Player.CentralLine.Front);
    lightPosition.SetLength(1.5f * ShipMeasure::YLength);
    lightPosition.Add(_race.Player.CentralLine.Front);
    gluLookAt(lightPosition, _race.Player.CentralLine.Front, Constants::UpAxis);

    CalculateShadowMatrix(lightPosition);

    _shipsRenderer.RenderShip(_race.Player, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glPopMatrix();
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void ShipShadowMapUpdater::CalculateShadowMatrix(Vector3& lightPosition)
{
    Matrix4 view, perspective, bias;
    view.LookAt(lightPosition, _race.Player.CentralLine.Front, Constants::UpAxis);
    perspective.Perspective(Math::PiHalf, Constants::ScreenAspect, 0.1f, Constants::SceneRadiusDouble);
    bias.SetBias();
    _shipShadowMap.ShadowMatrix.SetIdentity();
    _shipShadowMap.ShadowMatrix.Mul(bias);
    _shipShadowMap.ShadowMatrix.Mul(perspective);
    _shipShadowMap.ShadowMatrix.Mul(view);
}

void ShipShadowMapUpdater::InitFBO()
{
    glGenTextures(1, &_shipShadowMap.TextureId);
    glBindTexture(GL_TEXTURE_2D, _shipShadowMap.TextureId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH_COMPONENT24, _resolutionWidth, _resolutionHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 0.0f, 0.0f, 0.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glBindTexture(GL_TEXTURE_2D, _shipShadowMap.TextureId);
    glGenFramebuffers(1, &_fboId);
    glBindFramebuffer(GL_FRAMEBUFFER, _fboId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, _shipShadowMap.TextureId, 0);
    GLenum drawBuffers[] = { GL_NONE };
    glDrawBuffers(1, drawBuffers);
    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    Assert::True(status == GL_FRAMEBUFFER_COMPLETE);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

ShipShadowMapUpdater* ShipShadowMapUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new ShipShadowMapUpdater(
        resolver.Resolve<Race>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<ShadowMaps>());
}
