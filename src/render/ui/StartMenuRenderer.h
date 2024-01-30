#pragma once

#include <calc/Vector3.h>
#include <calc/SinPeriodValue.h>
#include <core/Game.h>
#include <gl/TexturedRect.h>
#include <ui/StartMenuScreen.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/StarsRenderer.h>
#include <render/ui/ScreenRenderer.h>

class StartMenuRenderer : public ScreenRenderer
{
    BackgroundRenderer _backgroundRenderer;
    StarsRenderer _starsRenderer;
    TexturedRect _startGameItem;
    TexturedRect _exitItem;
    Vector3 _turnVector;
    float _turnDegrees;
    SinPeriodValue _selectedItemAlpha;
    Vector3 _zeroVector;
    Vector3 _forwardVector;

public:
    StartMenuRenderer();

    void Init() override;
    void Render(Game& game) override;

private:
    void RenderBackground();
    void RenderMenu(StartMenuScreen& screen);
    void SetAlphaForSelectedItem(StartMenuScreen& screen, StartMenuItem item);
};
