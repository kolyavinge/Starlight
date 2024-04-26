#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/TexturedRect.h>
#include <render/common/GraphicItemCollection.h>

class RacePositionRenderer : public Object
{
    TexturedRect& _position1Item;
    TexturedRect& _position2Item;
    TexturedRect& _position3Item;
    TexturedRect& _position4Item;

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
