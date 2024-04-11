#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/IScreenNavigator.h>
#include <ui/ScreenManager.h>
#include <render/ui/RenderManager.h>
#include <vox/ui/VoxManager.h>

class ScreenNavigator : public Object, public IScreenNavigator
{
    ScreenManager* _screenManager;
    RenderManager* _renderManager;
    VoxManager* _voxManager;

public:
    ScreenNavigator();

    void Init(
        ScreenManager& screenManager,
        RenderManager& renderManager,
        VoxManager& voxManager);

    void NavigateTo(ScreenKind kind) override;
};

class ScreenNavigatorResolvingFactory : public ResolvingFactory<ScreenNavigator>
{
public:
    ScreenNavigator* Make(Resolver& resolver) override;
};
