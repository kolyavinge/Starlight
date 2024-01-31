#pragma once

#include <ui/Screen.h>
#include <ui/StartMenuScreen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>
#include <vox/MenuItemVox.h>

class StartMenuVox : public ScreenVox
{
    MenuItemVox<StartMenuItem> _menuItemVox;

public:
    void Init(SampleCollection& sampleCollection) override;
    void Voice(Screen& screen) override;
};
