#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>

class TrackThumbnail
{
public:
    inline static const float Width = 380.0f;
    inline static const float Height = 280.0f;
    inline static const float WidthHalf = Width / 2.0f;
    inline static const float HeightHalf = Height / 2.0f;
};

class TrackThumbnailRenderer : public Object
{
    inline static const int _trackPointStep = 100;

public:
    void Render(Track& track, float rotateDegrees);

private:
    void RenderTrack(Track& track);
    void RenderStartFinishLine(Track& track);
    void RenderBorder();
};

class TrackThumbnailRendererResolvingFactory : public ResolvingFactory<TrackThumbnailRenderer>
{
public:
    TrackThumbnailRenderer* Make(Resolver& resolver) override;
};
