#pragma once

class IScreenNavigator
{
public:
    virtual void NavigateToStartMenu() = 0;
    virtual void NavigateToTrackSelector() = 0;
    virtual void NavigateToPauseMenu() = 0;
    virtual void NavigateToRace() = 0;
};
