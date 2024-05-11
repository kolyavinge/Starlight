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
    ShipRenderer& shipRenderer,
    ShadowMaps& shadowMaps) :
    _resolutionWidth(2000),
    _resolutionHeight(2000),
    _race(race),
    _shipRenderer(shipRenderer),
    _shipShadowMaps(shadowMaps.ShipShadowMaps)
{
    for (int i = 0; i < _shipShadowMaps.GetCount(); i++)
    {
        InitFBO(_shipShadowMaps[i]);
    }
}

void ShipShadowMapUpdater::Update()
{
    for (int i = 0; i < _shipShadowMaps.GetCount(); i++)
    {
        Update(*_race.AllShips[i], _shipShadowMaps[i]);
    }
}

void ShipShadowMapUpdater::Update(Ship& ship, ShadowMap& shadowMap)
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glPushMatrix();
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMap.FBOId);

    glViewport(0, 0, _resolutionWidth, _resolutionHeight);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    Vector3 lightPosition(RenderConstants::GlobalLightPosition);
    lightPosition.Sub(ship.CentralLine.Front);
    lightPosition.SetLength(1.5f * ShipMeasure::YLength);
    lightPosition.Add(ship.CentralLine.Front);
    gluLookAt(lightPosition, ship.CentralLine.Front, Constants::UpAxis);

    CalculateShadowMatrix(ship, shadowMap, lightPosition);

    _shipRenderer.Render(ship, 0);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glPopMatrix();
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void ShipShadowMapUpdater::CalculateShadowMatrix(Ship& ship, ShadowMap& shadowMap, Vector3& lightPosition)
{
    Matrix4 view, perspective, bias;
    view.LookAt(lightPosition, ship.CentralLine.Front, Constants::UpAxis);
    perspective.Perspective(Math::PiHalf, Constants::ScreenAspect, 0.1f, Constants::SceneRadiusDouble);
    bias.SetBias();
    shadowMap.ShadowMatrix.SetIdentity();
    shadowMap.ShadowMatrix.Mul(bias);
    shadowMap.ShadowMatrix.Mul(perspective);
    shadowMap.ShadowMatrix.Mul(view);
}

void ShipShadowMapUpdater::InitFBO(ShadowMap& shadowMap)
{
    glGenTextures(1, &shadowMap.TextureId);
    glBindTexture(GL_TEXTURE_2D, shadowMap.TextureId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_DEPTH_COMPONENT24, _resolutionWidth, _resolutionHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 1.0f, 0.0f, 0.0f, 0.0f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_REF_TO_TEXTURE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
    glBindTexture(GL_TEXTURE_2D, shadowMap.TextureId);
    glGenFramebuffers(1, &shadowMap.FBOId);
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMap.FBOId);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, shadowMap.TextureId, 0);
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
        resolver.Resolve<ShipRenderer>(),
        resolver.Resolve<ShadowMaps>());
}
