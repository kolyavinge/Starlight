#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <model/Weapon.h>
#include <gl/TextRenderer.h>

class BulletsCountRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _bulletsString;

public:
    BulletsCountRenderer(TextRenderer& textRenderer);

    void Render(Weapon& weapon);
};
