#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <ui/PauseMenuScreen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>
#include <vox/MenuItemVox.h>

class PauseMenuVox : public ScreenVox
{
    MenuItemVox<PauseMenuItem> _menuItemVox;

public:
    PauseMenuVox();

    void Init(SampleCollection& sampleCollection) override;
    void Voice(Screen& screen) override;
};

class PauseMenuVoxResolvingFactory : public ResolvingFactory<PauseMenuVox>
{
public:
    PauseMenuVox* Make(Resolver& resolver) override;
};
