#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <model/NitroCollection.h>
#include <gl/TextRenderer.h>

class NitroCountRenderer : public Object
{
    TextRenderer& _textRenderer;
    String _nitrosString;
    String _nitrosCountString;

public:
    NitroCountRenderer(TextRenderer& textRenderer);

    void Render(NitroCollection& nitros);
};
