#pragma once

#include <lib/Object.h>
#include <model/Track.h>

class TrackThumbnailRenderer : public Object
{
    const int _trackPointStep = 100;
    float _rotateDegrees;

public:
    TrackThumbnailRenderer();

    float GetWidth();
    float GetHeight();
    void Render(Track& track, bool isRotated);

private:
    void RenderTrack(Track& track);
    void RenderStartFinishLine(Track& track);
};
