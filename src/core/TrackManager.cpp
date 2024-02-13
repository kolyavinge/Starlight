#include <model/track/RoadTrack1.h>
#include <model/track/RoadTrack2.h>
#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    _currentTrack = new RoadTrack2();
}

TrackManager::~TrackManager()
{
    delete _currentTrack;
}

Track& TrackManager::GetCurrentTrack()
{
    return *_currentTrack;
}
