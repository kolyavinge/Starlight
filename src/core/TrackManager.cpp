#include <core/TrackManager.h>

TrackManager::TrackManager()
{
    Track1.Init();
    Track2.Init();
    Track3.Init();
    Track4.Init();
}

TrackManager* TrackManagerResolvingFactory::Make(Resolver&)
{
    return new TrackManager();
}
