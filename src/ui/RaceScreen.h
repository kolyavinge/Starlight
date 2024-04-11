#pragma once

#include <lib/di/ResolvingFactory.h>
#include <core/Camera.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/Screen.h>
#include <ui/IScreenNavigator.h>

class RaceScreen : public Screen
{
    Camera& _camera;
    Race& _race;

public:
    RaceScreen(
        IScreenNavigator& navigator,
        InputDevices& inputDevices,
        Camera& camera,
        Race& race);

    void Update() override;
    void ProcessInput() override;
};

class RaceScreenResolvingFactory : public ResolvingFactory<RaceScreen>
{
public:
    RaceScreen* Make(Resolver& resolver) override;
};
