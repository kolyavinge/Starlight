#pragma once

#include <lib/Object.h>
#include <gl/ITexturedRect.h>

class ShadowedTexturedRect : public Object, public ITexturedRect
{
    ITexturedRect& _texturedRect;

public:
    ShadowedTexturedRect(ITexturedRect& texturedRect);

    void Render() override;
    int GetWidth() override;
    int GetHeight() override;
};
