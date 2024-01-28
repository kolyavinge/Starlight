#pragma once

#include <core/Game.h>
#include <render/ui/ScreenRenderer.h>

class PauseMenuRenderer : public ScreenRenderer
{
public:
    void Render(Game& game) override;
};
