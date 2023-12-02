#pragma once

#include "lib/Object.h"
#include "model/Track.h"

class DebugTrackRenderer : public Object
{
public:
    void Render(Track& track);

private:
    void RenderInsideLines(Track& track);
    void RenderOutsideLines(Track& track);
    void RenderAcrossLines(Track& track);
    void RenderStartFinishLine(Track& track);
};
