#pragma once

#include <core/TrackManager.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class TrackSelectorScreen : public Screen
{
    TrackManager& _trackManager;
    Race& _race;

public:
    TrackSelectorScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        TrackManager& trackManager,
        Race& race);

    void Activate() override;
    void ProcessInput() override;
};
