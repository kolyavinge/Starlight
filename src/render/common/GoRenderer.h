#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/TexturedRect.h>
#include <render/common/GraphicItemCollection.h>

class GoRenderer : public Object
{
    TexturedRect& _goItem;
    float _alpha;

public:
    GoRenderer(GraphicItemCollection& graphicItemCollection);

    void Init();
    void Render();
};

class GoRendererResolvingFactory : public ResolvingFactory<GoRenderer>
{
public:
    GoRenderer* Make(Resolver& resolver) override;
};
