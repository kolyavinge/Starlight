#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/PauseMenuScreen.h>
#include <vox/common/AudioDataCollection.h>
#include <vox/ui/ScreenVox.h>
#include <vox/ui/MenuItemVox.h>

class PauseMenuVox : public ScreenVox
{
    MenuItemVox<PauseMenuItem> _menuItemVox;

public:
    PauseMenuVox(AudioDataCollection& audioDataCollection);

    void Voice(Screen& screen) override;
};

class PauseMenuVoxResolvingFactory : public ResolvingFactory<PauseMenuVox>
{
public:
    PauseMenuVox* Make(Resolver& resolver) override;
};
