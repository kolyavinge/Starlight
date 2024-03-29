#pragma once

#include <lib/di/ResolvingFactory.h>
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
    LinearMenuItemSelector<TrackSelectorItem> _itemSelector;
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
    int GetTrackGridRowsCount();
    int GetTrackGridColsCount();
    Track& GetTrackByCell(int row, int col);
    bool IsMenuSelectionActive();
    bool IsTrackSelectionActive();

private:
    Track& GetTrackByItem(TrackSelectorItem item);
};

class TrackSelectorScreenResolvingFactory : public ResolvingFactory<TrackSelectorScreen>
{
public:
    TrackSelectorScreen* Make(Resolver& resolver) override;
};
