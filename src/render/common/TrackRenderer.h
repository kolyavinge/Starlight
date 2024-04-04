#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>
#include <model/TrackEdge.h>
#include <gl/Texture.h>

class TrackRenderer : public Object
{
    Texture _groundTexture;
    Texture _groundFinishTexture;
    Texture _edgeTexture;

public:
    void Init();
    void Render(Track& track);

private:
    void RenderTrack(Track& track);
    void RenderSegment(Track& track, int startPointIndex, int endPointIndex, int step);
    void RenderEdges(Track& track);
    void RenderEdge(TrackEdge& edge, TrackEdge& nextEdge);
};

class TrackRendererResolvingFactory : public ResolvingFactory<TrackRenderer>
{
public:
    TrackRenderer* Make(Resolver& resolver) override;
};
