#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    Track1.Init();
    Track2.Init();
    Track3.Init();
    Track4.Init();
    AllTracks[0] = &Track1;
    AllTracks[1] = &Track2;
    AllTracks[2] = &Track3;
    AllTracks[3] = &Track4;
}

TrackManager* TrackManagerResolvingFactory::Make(Resolver&)
{
    return new TrackManager();
}
