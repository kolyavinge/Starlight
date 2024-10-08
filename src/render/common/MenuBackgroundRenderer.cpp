#include <lib/Random.h>
#include <calc/Geometry.h>
#include <gl/opengl.h>
#include <render/common/MenuBackgroundRenderer.h>

MenuBackgroundRenderer::MenuBackgroundRenderer(
    BackgroundRenderer& backgroundRenderer,
    StarsRenderer& starsRenderer) :
    _backgroundRenderer(backgroundRenderer),
    _starsRenderer(starsRenderer)
{
    Random rand;
    _turnVector.Set(
        rand.GetFloatFromZeroToOne() - 0.5f,
        rand.GetFloatFromZeroToOne() - 0.5f,
        rand.GetFloatFromZeroToOne() - 0.5f);
    _turnDegrees = rand.GetFloatFromZeroToN(720.0f) - 360.0f;
    _forwardVector.Set(0.0f, 1.0f, 0.0f);
}

void MenuBackgroundRenderer::Render()
{
    glLoadIdentity();
    gluPerspective(60.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    gluLookAt(_zeroVector, _forwardVector, Constants::UpAxis);
    glRotatef(_turnDegrees, _turnVector);
    _backgroundRenderer.Render();
    _starsRenderer.Render();
    _turnDegrees = Geometry::NormalizeDegrees(_turnDegrees + 0.05f);
}

MenuBackgroundRenderer* MenuBackgroundRendererResolvingFactory::Make(Resolver& resolver)
{
    return new MenuBackgroundRenderer(
        resolver.Resolve<BackgroundRenderer>(),
        resolver.Resolve<StarsRenderer>());
}
