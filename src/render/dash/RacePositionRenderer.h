#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/ShadowedTexturedRect.h>
#include <render/common/GraphicItemCollection.h>

class RacePositionRenderer : public Object
{
    ShadowedTexturedRect _position1Item;
    ShadowedTexturedRect _position2Item;
    ShadowedTexturedRect _position3Item;
    ShadowedTexturedRect _position4Item;

public:
    RacePositionRenderer(GraphicItemCollection& graphicItemCollection);

    void Render(Ship& player);

private:
    ITexturedRect& GetPositionItem(Ship& player);
};

class RacePositionRendererResolvingFactory : public ResolvingFactory<RacePositionRenderer>
{
public:
    RacePositionRenderer* Make(Resolver& resolver);
};
