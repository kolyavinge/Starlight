#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <core/Laps.h>
#include <gl/TextRenderer.h>

class LapsCountRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _lapsCountString;

public:
    LapsCountRenderer(TextRenderer& textRenderer);

    void Render(Laps& laps);
};
