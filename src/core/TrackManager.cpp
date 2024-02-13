#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    _currentTrack = &Track2;
}

void TrackManager::Init()
{
    Track1.Init();
    Track2.Init();
    Track3.Init();
    Track4.Init();
}

Track& TrackManager::GetCurrentTrack()
{
    return *_currentTrack;
}
