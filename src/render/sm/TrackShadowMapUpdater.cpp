#include <lib/Math.h>
#include <calc/Vector3.h>
#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/sm/TrackShadowMapUpdater.h>

TrackShadowMapUpdater::TrackShadowMapUpdater(
    TrackRenderer& trackRenderer,
    ShadowMaps& shadowMaps,
    ShadowMapFramebufferGenerator& shadowMapFramebufferGenerator) :
    _resolutionWidth(5000),
    _resolutionHeight(5000),
    _trackRenderer(trackRenderer),
    _trackShadowMap(shadowMaps.TrackShadowMap)
{
    shadowMapFramebufferGenerator.Generate(
        _resolutionWidth, _resolutionHeight, _trackShadowMap.FBOId, _trackShadowMap.TextureId);
}

void TrackShadowMapUpdater::Update()
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glPushMatrix();
    glBindFramebuffer(GL_FRAMEBUFFER, _trackShadowMap.FBOId);

    glViewport(0, 0, _resolutionWidth, _resolutionHeight);
    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(90.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    Vector3 lightPosition(RenderConstants::GlobalLightPosition);
    Vector3 lookAt(1.0f, 1.0f, 0.0f);
    gluLookAt(lightPosition, lookAt, Constants::UpAxis);

    CalculateShadowMatrix(lightPosition, lookAt);

    _trackRenderer.FillDepthBufferForShadow();

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glPopMatrix();
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void TrackShadowMapUpdater::CalculateShadowMatrix(Vector3& lightPosition, Vector3& lookAt)
{
    Matrix4 view, perspective, bias;
    view.LookAt(lightPosition, lookAt, Constants::UpAxis);
    perspective.Perspective(Math::PiHalf, Constants::ScreenAspect, 0.1f, Constants::SceneRadiusDouble);
    bias.SetBias();
    _trackShadowMap.ShadowMatrix.SetIdentity();
    _trackShadowMap.ShadowMatrix.Mul(bias);
    _trackShadowMap.ShadowMatrix.Mul(perspective);
    _trackShadowMap.ShadowMatrix.Mul(view);
}

TrackShadowMapUpdater* TrackShadowMapUpdaterResolvingFactory::Make(Resolver& resolver)
{
    return new TrackShadowMapUpdater(
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<ShadowMaps>(),
        resolver.Resolve<ShadowMapFramebufferGenerator>());
}
