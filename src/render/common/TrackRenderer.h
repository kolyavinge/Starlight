#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>
#include <gl/Texture.h>

class TrackRenderer : public Object
{
    Texture _groundTexture;
    Texture _groundFinishTexture;

public:
    void Init();
    void Render(Track& track);

private:
    void RenderTrack(Track& track);
    void RenderEdges(Track& track);
    void RenderSegment(Track& track, int startPointIndex, int endPointIndex, int step);
};

class TrackRendererResolvingFactory : public ResolvingFactory<TrackRenderer>
{
public:
    TrackRenderer* Make(Resolver& resolver) override;
};
