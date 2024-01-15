#include <model/track/RoadTrack1.h>
#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    _currentTrack = new RoadTrack1();
}

TrackManager::~TrackManager()
{
    delete _currentTrack;
}

Track& TrackManager::GetCurrentTrack()
{
    return *_currentTrack;
}
