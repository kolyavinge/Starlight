#include <gl/opengl.h>
#include <lib/Exceptions.h>
#include <core/Constants.h>
#include <render/common/RenderConstants.h>
#include <render/dash/RacePositionRenderer.h>

RacePositionRenderer::RacePositionRenderer(GraphicItemCollection& graphicItemCollection) :
    _position1Item(graphicItemCollection.Position1Item),
    _position2Item(graphicItemCollection.Position2Item),
    _position3Item(graphicItemCollection.Position3Item),
    _position4Item(graphicItemCollection.Position4Item)
{
}

void RacePositionRenderer::Render(Ship& player)
{
    ITexturedRect& positionItem = GetPositionItem(player);

    glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, 1.0f);

    glPushMatrix();

    glTranslatef(10.0f, Constants::ScreenHeight - 10.0f - 0.7f * positionItem.GetHeight(), 0.0f);
    glScalef(0.7f, 0.7f, 1.0f);
    positionItem.Render();

    glPopMatrix();
}

ITexturedRect& RacePositionRenderer::GetPositionItem(Ship& player)
{
    if (player.RacePosition == 1)
    {
        return _position1Item;
    }
    else if (player.RacePosition == 2)
    {
        return _position2Item;
    }
    else if (player.RacePosition == 3)
    {
        return _position3Item;
    }
    else if (player.RacePosition == 4)
    {
        return _position4Item;
    }
    else
    {
        throw ArgumentException();
    }
}

RacePositionRenderer* RacePositionRendererResolvingFactory::Make(Resolver& resolver)
{
    return new RacePositionRenderer(
        resolver.Resolve<GraphicItemCollection>());
}
