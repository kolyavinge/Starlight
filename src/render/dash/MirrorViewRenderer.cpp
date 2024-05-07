#include <calc/Vector3.h>
#include <core/Constants.h>
#include <gl/opengl.h>
#include <render/dash/MirrorViewRenderer.h>

MirrorViewRenderer::MirrorViewRenderer(
    Race& race,
    BackgroundRenderer& backgroundRenderer,
    ShipsRenderer& shipsRenderer,
    TrackRenderer& trackRenderer,
    BulletsRenderer& bulletsRenderer,
    PowerUpRenderer& powerUpRenderer,
    ExplosionRenderer& explosionRenderer) :
    _mirrorWidth(250.0f),
    _mirrorHeight(_mirrorWidth / Constants::ScreenAspect),
    _resolutionWidth(600),
    _resolutionHeight((unsigned int)(_resolutionWidth / Constants::ScreenAspect)),
    _race(race),
    _backgroundRenderer(backgroundRenderer),
    _shipsRenderer(shipsRenderer),
    _trackRenderer(trackRenderer),
    _bulletsRenderer(bulletsRenderer),
    _powerUpRenderer(powerUpRenderer),
    _explosionRenderer(explosionRenderer)
{
    _fboId = 0;
    _textureId = 0;
    InitFBO();
}

void MirrorViewRenderer::Render()
{
    UpdateTexture();
    RenderBorder();
    RenderTexture();
}

void MirrorViewRenderer::UpdateTexture()
{
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);

    glPushMatrix();
    glBindFramebuffer(GL_FRAMEBUFFER, _fboId);
    glViewport(0, 0, _resolutionWidth, _resolutionHeight);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, Constants::ScreenAspect, 0.1, Constants::SceneRadiusDouble);
    Vector3 lookBehind(_race.Player.CentralLine.Rear);
    lookBehind.Sub(_race.Player.CentralLine.Front);
    lookBehind.Add(_race.Player.CentralLine.Rear);
    gluLookAt(_race.Player.CentralLine.Rear, lookBehind, Constants::UpAxis);

    _backgroundRenderer.Render();
    _trackRenderer.Render();
    _shipsRenderer.RenderEnemies(_race.Enemies);
    _bulletsRenderer.Render(_race.Player, _race.Enemies);
    _explosionRenderer.Render(_race.Player, _race.AllShips);
    _powerUpRenderer.Render(_race.PowerUps);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
    glPopMatrix();
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void MirrorViewRenderer::RenderTexture()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureId);

    glPushMatrix();
    glTranslatef(
        (Constants::ScreenWidth - _mirrorWidth) / 2.0f,
        Constants::ScreenHeight - _mirrorHeight - 4.0f,
        0.0f);
    glBegin(GL_QUADS);

    glTexCoord2i(0, 0);
    glVertex2f(0.0f, 0.0f);

    glTexCoord2i(1, 0);
    glVertex2f(_mirrorWidth, 0.0f);

    glTexCoord2i(1, 1);
    glVertex2f(_mirrorWidth, _mirrorHeight);

    glTexCoord2i(0, 1);
    glVertex2f(0.0f, _mirrorHeight);

    glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);
}

void MirrorViewRenderer::RenderBorder()
{
    const float borderSize = 1.0f;
    glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_MULTISAMPLE);
    glEnable(GL_BLEND);
    glPushMatrix();
    glTranslatef(
        (Constants::ScreenWidth - _mirrorWidth) / 2.0f - borderSize,
        Constants::ScreenHeight - _mirrorHeight - 4.0f - borderSize,
        0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.0f);
    glVertex2f(_mirrorWidth + 2.0f * borderSize, 0.0f);
    glVertex2f(_mirrorWidth + 2.0f * borderSize, _mirrorHeight + 2.0f * borderSize);
    glVertex2f(0.0f, _mirrorHeight + 2.0f * borderSize);
    glEnd();
    glPopMatrix();
    glDisable(GL_BLEND);
    glDisable(GL_MULTISAMPLE);
}

void MirrorViewRenderer::InitFBO()
{
    glGenFramebuffers(1, &_fboId);
    glBindFramebuffer(GL_FRAMEBUFFER, _fboId);

    glGenTextures(1, &_textureId);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _textureId);
    glTexStorage2D(GL_TEXTURE_2D, 1, GL_RGBA8, _resolutionWidth, _resolutionHeight);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _textureId, 0);

    unsigned int depthBufferId;
    glGenRenderbuffers(1, &depthBufferId);
    glBindRenderbuffer(GL_RENDERBUFFER, depthBufferId);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, _resolutionWidth, _resolutionHeight);

    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, depthBufferId);

    GLenum drawBuffers[] = { GL_COLOR_ATTACHMENT0 };
    glDrawBuffers(1, drawBuffers);

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

MirrorViewRenderer* MirrorViewRendererResolvingFactory::Make(Resolver& resolver)
{
    return new MirrorViewRenderer(
        resolver.Resolve<Race>(),
        resolver.Resolve<BackgroundRenderer>(),
        resolver.Resolve<ShipsRenderer>(),
        resolver.Resolve<TrackRenderer>(),
        resolver.Resolve<BulletsRenderer>(),
        resolver.Resolve<PowerUpRenderer>(),
        resolver.Resolve<ExplosionRenderer>());
}
