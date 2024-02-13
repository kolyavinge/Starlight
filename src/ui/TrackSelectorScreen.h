#pragma once

#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>
#include <ui/MenuItemSelector.h>
#include <ui/LinearMenuItemSelector.h>
#include <ui/GridMenuItemSelector.h>

enum class TrackSelectorItem
{
    Track1,
    Track2,
    Track3,
    Track4,
    Race,
    Back
};

class TrackSelectorScreen : public Screen
{
    LinearMenuItemSelector<TrackSelectorItem, 2> _itemSelector;
    GridMenuItemSelector<TrackSelectorItem, 2, 2> _trackSelector;
    MenuItemSelector<TrackSelectorItem>* _activeSelector;
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
    Track& GetSelectedTrack();

private:
    bool IsMenuActive();
};
