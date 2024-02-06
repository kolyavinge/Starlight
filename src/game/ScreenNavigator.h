#pragma once

#include <ui/IScreenNavigator.h>
#include <ui/ScreenManager.h>
#include <render/ui/RenderManager.h>
#include <vox/VoxManager.h>

class ScreenNavigator : public IScreenNavigator
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
