#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/TrackThumbnailRenderer.h>

void TrackThumbnailRenderer::Render(Track& track, float rotateDegrees)
{
    //RenderBorder();
    glPushMatrix();
    glTranslatef(TrackThumbnail::WidthHalf, TrackThumbnail::HeightHalf, 0.0f);

    glPushMatrix();
    glRotatef(45.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(rotateDegrees, 0.0f, 0.0f, 1.0f);
    glScalef(0.35f, 0.35f, 0.35f);
    RenderTrack(track);
    RenderStartFinishLine(track);
    glPopMatrix();

    glPopMatrix();
}

void TrackThumbnailRenderer::RenderTrack(Track& track)
{
    glBegin(GL_QUADS);

    int i;
    for (i = _trackPointStep; i < track.PointsCount; i += _trackPointStep)
    {
        glVertex3f(track.InsidePointsInverseZ[i - _trackPointStep]);
        glVertex3f(track.InsidePointsInverseZ[i]);
        glVertex3f(track.OutsidePointsInverseZ[i]);
        glVertex3f(track.OutsidePointsInverseZ[i - _trackPointStep]);
    }

    glVertex3f(track.InsidePointsInverseZ[i - _trackPointStep]);
    glVertex3f(track.InsidePointsInverseZ[0]);
    glVertex3f(track.OutsidePointsInverseZ[0]);
    glVertex3f(track.OutsidePointsInverseZ[i - _trackPointStep]);

    glEnd();
}

void TrackThumbnailRenderer::RenderStartFinishLine(Track& track)
{
    glColor4f(0.0f, 0.0f, 0.0f, 0.9f);
    glBegin(GL_QUADS);

    glVertex3f(track.InsidePointsInverseZ[track.StartFinishLineIndex]);
    glVertex3f(track.InsidePointsInverseZ[track.StartFinishLineIndex + _trackPointStep / 2]);
    glVertex3f(track.OutsidePointsInverseZ[track.StartFinishLineIndex + _trackPointStep / 2]);
    glVertex3f(track.OutsidePointsInverseZ[track.StartFinishLineIndex]);

    glEnd();
}

void TrackThumbnailRenderer::RenderBorder()
{
    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(TrackThumbnail::Width, 0.0f, 0.0f);
    glVertex3f(TrackThumbnail::Width, TrackThumbnail::Height, 0.0f);
    glVertex3f(0.0f, TrackThumbnail::Height, 0.0f);
    glEnd();
}

TrackThumbnailRenderer* TrackThumbnailRendererResolvingFactory::Make(Resolver&)
{
    return new TrackThumbnailRenderer();
}
