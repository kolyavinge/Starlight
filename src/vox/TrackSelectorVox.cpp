#include <ui/TrackSelectorScreen.h>
#include <vox/TrackSelectorVox.h>

TrackSelectorVox::TrackSelectorVox(AudioDataCollection& audioDataCollection) :
    _menuItemVox(TrackSelectorItem::Back, audioDataCollection)
{
}

void TrackSelectorVox::Voice(Screen& screen)
{
    TrackSelectorScreen& trackSelectorScreen = (TrackSelectorScreen&)screen;
    _menuItemVox.Voice(trackSelectorScreen.GetSelectedItem());
}

TrackSelectorVox* TrackSelectorVoxResolvingFactory::Make(Resolver& resolver)
{
    return new TrackSelectorVox(resolver.Resolve<AudioDataCollection>());
}
