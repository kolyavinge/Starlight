#pragma once

#include <lib/Object.h>
#include <gl/TexturedRect.h>

class GoRenderer : public Object
{
    TexturedRect* _goItem;
    float _alpha;

public:
    GoRenderer();

    void Init(TexturedRect& goItem);
    void Reset();
    void Render();
};
