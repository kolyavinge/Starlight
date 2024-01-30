#pragma once

#include <model/Track.h>
#include <core/IGameStarter.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class TrackSelectorScreen : public Screen
{
    IGameStarter& _gameStarter;
    //Track* _selectedTrack;

public:
    TrackSelectorScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        IGameStarter& gameStarter);

    void Activate() override;
    void ProcessInput() override;
};
