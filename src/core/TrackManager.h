#pragma once

#include <lib/Object.h>
#include <model/Track.h>

class TrackManager : public Object
{
    Track* _currentTrack;

public:
    TrackManager();
    ~TrackManager();

    Track& GetCurrentTrack();
};
