#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <input/InputDevices.h>
#include <ui/ScreenManager.h>
#include <render/ui/RenderManager.h>
#include <vox/VoxManager.h>
#include <game/ScreenNavigator.h>

class Game : public Object
{
    ScreenManager& _screenManager;
    RenderManager& _renderManager;
    VoxManager& _voxManager;
    ScreenNavigator& _screenNavigator;

public:
    Race& Race;
    InputDevices& InputDevices;

    Game(
        ScreenManager& screenManager,
        RenderManager& renderManager,
        VoxManager& voxManager,
        ScreenNavigator& screenNavigator,
        ::InputDevices& inputDevices,
        ::Race& race);

    void Init();
    void Update();
    void RenderCurrentScreen();
    void VoiceCurrentScreen();
};

class GameResolvingFactory : public ResolvingFactory<Game>
{
public:
    Game* Make(Resolver& resolver) override;
};
