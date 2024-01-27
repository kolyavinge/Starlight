#pragma once

#include <model/Track.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class TrackSelectorScreen : public Screen
{
    //Track* _selectedTrack;

public:
    TrackSelectorScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices);

    void ProcessInput() override;
};
