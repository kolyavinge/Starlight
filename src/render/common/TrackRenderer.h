#pragma once

#include <lib/Object.h>
#include <model/Track.h>

class TrackRenderer : public Object
{
public:
    void Render(Track& track);

private:
    void RenderTrack(Track& track);
    void RenderEdges(Track& track);
};
