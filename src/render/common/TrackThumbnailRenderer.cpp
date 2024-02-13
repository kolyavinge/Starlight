#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/TrackThumbnailRenderer.h>

TrackThumbnailRenderer::TrackThumbnailRenderer()
{
    _rotateDegrees = 0.0f;
}

float TrackThumbnailRenderer::GetWidth()
{
    return 200.0f;
}

float TrackThumbnailRenderer::GetHeight()
{
    return 200.0f;
}

void TrackThumbnailRenderer::Render(Track& track, bool isRotated)
{
    glPushMatrix();
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 0.8f);
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
    if (isRotated)
    {
        glRotatef(_rotateDegrees, 0.0f, 0.0f, 1.0f);
        _rotateDegrees -= 1.0f;
    }
    glScalef(0.35f, 0.35f, 0.35f);
    RenderTrack(track);
    RenderStartFinishLine(track);
    glPopMatrix();
}

void TrackThumbnailRenderer::RenderTrack(Track& track)
{
    glBegin(GL_QUADS);

    int i;
    for (i = _trackPointStep; i < track.PointsCount; i += _trackPointStep)
    {
        glVertex3f(track.InsidePoints[i - _trackPointStep]);
        glVertex3f(track.InsidePoints[i]);
        glVertex3f(track.OutsidePoints[i]);
        glVertex3f(track.OutsidePoints[i - _trackPointStep]);
    }

    glVertex3f(track.InsidePoints[i - _trackPointStep]);
    glVertex3f(track.InsidePoints[0]);
    glVertex3f(track.OutsidePoints[0]);
    glVertex3f(track.OutsidePoints[i - _trackPointStep]);

    glEnd();
}

void TrackThumbnailRenderer::RenderStartFinishLine(Track& track)
{
    glColor4f(0.0f, 0.0f, 0.0f, 0.8f);
    glBegin(GL_QUADS);

    glVertex3f(track.InsidePoints[track.StartFinishLineIndex]);
    glVertex3f(track.InsidePoints[track.StartFinishLineIndex + _trackPointStep / 2]);
    glVertex3f(track.OutsidePoints[track.StartFinishLineIndex + _trackPointStep / 2]);
    glVertex3f(track.OutsidePoints[track.StartFinishLineIndex]);

    glEnd();
}
