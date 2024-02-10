#include <ui/Screen.h>
#include <game/ScreenNavigator.h>

ScreenNavigator::ScreenNavigator()
{
    _screenManager = nullptr;
    _renderManager = nullptr;
    _voxManager = nullptr;
}

void ScreenNavigator::Init(
    ScreenManager& screenManager,
    RenderManager& renderManager,
    VoxManager& voxManager)
{
    _screenManager = &screenManager;
    _renderManager = &renderManager;
    _voxManager = &voxManager;
}

void ScreenNavigator::NavigateTo(ScreenKind kind)
{
    Screen* screen = &_screenManager->GetCurrentScreen();
    ScreenRenderer* renderer = nullptr;
    ScreenVox* vox = nullptr;
    if (screen != nullptr)
    {
        renderer = &_renderManager->GetScreenRenderer(*screen);
        vox = &_voxManager->GetScreenVox(*screen);
        screen->Deactivate();
        renderer->Deactivate();
        vox->Deactivate();
    }

    screen = &_screenManager->GetScreen(kind);
    renderer = &_renderManager->GetScreenRenderer(*screen);
    vox = &_voxManager->GetScreenVox(*screen);

    _screenManager->SetCurrentScreen(*screen);

    screen->Activate();
    renderer->Activate();
    vox->Activate();
}
