#pragma once

#include <core/Game.h>
#include <render/ui/ScreenRenderer.h>

class TrackSelectorRenderer : public ScreenRenderer
{
public:
    void Init() override;
    void Render(Game& game) override;
};
