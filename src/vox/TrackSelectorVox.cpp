#include <ui/TrackSelectorScreen.h>
#include <vox/TrackSelectorVox.h>

TrackSelectorVox::TrackSelectorVox() :
    _menuItemVox(TrackSelectorItem::Back)
{
}

void TrackSelectorVox::Init(SampleCollection& sampleCollection)
{
    _menuItemVox.Init(sampleCollection);
}

void TrackSelectorVox::Voice(Screen& screen)
{
    TrackSelectorScreen& trackSelectorScreen = (TrackSelectorScreen&)screen;
    _menuItemVox.Voice(trackSelectorScreen.GetSelectedItem());
}

TrackSelectorVox* TrackSelectorVoxResolvingFactory::Make(Resolver&)
{
    return new TrackSelectorVox();
}
