#pragma once

#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/MenuItemSelector.h>

enum class TrackSelectorItem
{
    Race,
    Back,
};

class TrackSelectorScreen : public Screen
{
    MenuItemSelector<TrackSelectorItem, 2> _selector;
    TrackManager& _trackManager;
    Race& _race;

public:
    TrackSelectorScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        TrackManager& trackManager,
        Race& race);

    TrackSelectorItem GetSelectedItem();
    void Activate(Screen* prevScreen) override;
    void ProcessInput() override;
};
