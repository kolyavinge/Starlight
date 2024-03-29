#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>

class TrackRenderer : public Object
{
public:
    void Render(Track& track);

private:
    void RenderTrack(Track& track);
    void RenderEdges(Track& track);
};

class TrackRendererResolvingFactory : public ResolvingFactory<TrackRenderer>
{
public:
    TrackRenderer* Make(Resolver& resolver) override;
};
