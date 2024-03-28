#include <ui/TrackSelectorScreen.h>
#include <vox/TrackSelectorVox.h>

TrackSelectorVox::TrackSelectorVox(SampleCollection& sampleCollection) :
    _menuItemVox(TrackSelectorItem::Back)
{
    _menuItemVox.Init(sampleCollection);
}

void TrackSelectorVox::Voice(Screen& screen)
{
    TrackSelectorScreen& trackSelectorScreen = (TrackSelectorScreen&)screen;
    _menuItemVox.Voice(trackSelectorScreen.GetSelectedItem());
}

TrackSelectorVox* TrackSelectorVoxResolvingFactory::Make(Resolver& resolver)
{
    return new TrackSelectorVox(resolver.Resolve<SampleCollection>());
}
