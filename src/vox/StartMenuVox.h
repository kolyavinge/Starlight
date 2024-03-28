#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>
#include <vox/MenuItemVox.h>

class StartMenuVox : public ScreenVox
{
    MenuItemVox<StartMenuItem> _menuItemVox;

public:
    StartMenuVox(SampleCollection& sampleCollection);

    void Voice(Screen& screen) override;
};

class StartMenuVoxResolvingFactory : public ResolvingFactory<StartMenuVox>
{
public:
    StartMenuVox* Make(Resolver& resolver) override;
};
