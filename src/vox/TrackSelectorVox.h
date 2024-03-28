#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/TrackSelectorScreen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>
#include <vox/MenuItemVox.h>

class TrackSelectorVox : public ScreenVox
{
    MenuItemVox<TrackSelectorItem> _menuItemVox;

public:
    TrackSelectorVox();

    void Init(SampleCollection& sampleCollection) override;
    void Voice(Screen& screen) override;
};

class TrackSelectorVoxResolvingFactory : public ResolvingFactory<TrackSelectorVox>
{
public:
    TrackSelectorVox* Make(Resolver& resolver) override;
};
