#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <vox/common/AudioDataCollection.h>
#include <vox/ui/ScreenVox.h>
#include <vox/ui/MenuItemVox.h>

class StartMenuVox : public ScreenVox
{
    MenuItemVox<StartMenuItem> _menuItemVox;

public:
    StartMenuVox(AudioDataCollection& audioDataCollection);

    void Voice(Screen& screen) override;
};

class StartMenuVoxResolvingFactory : public ResolvingFactory<StartMenuVox>
{
public:
    StartMenuVox* Make(Resolver& resolver) override;
};
