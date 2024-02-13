#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    _currentTrack = &Track2;
}

Track& TrackManager::GetCurrentTrack()
{
    return *_currentTrack;
}
