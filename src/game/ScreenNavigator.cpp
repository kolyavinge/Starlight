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
    Screen* prevScreen = &_screenManager->GetCurrentScreen();
    ScreenRenderer* renderer = nullptr;
    ScreenVox* vox = nullptr;
    if (prevScreen != nullptr)
    {
        renderer = &_renderManager->GetScreenRenderer(*prevScreen);
        vox = &_voxManager->GetScreenVox(*prevScreen);
        prevScreen->Deactivate();
        renderer->Deactivate();
        vox->Deactivate();
    }

    Screen* screen = &_screenManager->GetScreen(kind);
    renderer = &_renderManager->GetScreenRenderer(*screen);
    vox = &_voxManager->GetScreenVox(*screen);

    _screenManager->SetCurrentScreen(*screen);

    screen->Activate(prevScreen);
    renderer->Activate(prevScreen);
    vox->Activate(prevScreen);
}
