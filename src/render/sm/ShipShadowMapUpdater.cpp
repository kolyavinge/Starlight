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
    ShadowMaps& shadowMaps,
    ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator) :
    _resolutionWidthHeight(2000),
    _race(race),
    _shipRenderer(shipRenderer),
    _shipShadowMaps(shadowMaps.ShipShadowMaps)
{
    for (int i = 0; i < _shipShadowMaps.GetCount(); i++)
    {
        shadowMapFramebufferGenerator.Generate(
            _resolutionWidthHeight, _resolutionWidthHeight, _shipShadowMaps[i].FBOId, _shipShadowMaps[i].TextureId);
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
    glBindFramebuffer(GL_FRAMEBUFFER, shadowMap.FBOId);
    glViewport(0, 0, _resolutionWidthHeight, _resolutionWidthHeight);
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
    _shipRenderer.FillDepthBufferForShadow(ship);
    glBindFramebuffer(GL_FRAMEBUFFER, 0);
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

ShipShadowMapUpdater* ShipShadowMapUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new ShipShadowMapUpdater(
        resolver.Resolve<Race>(),
        resolver.Resolve<ShipRenderer>(),
        resolver.Resolve<ShadowMaps>(),
        resolver.Resolve<ShadowMapFramebufferGenerator>());
}
