#pragma once

#include <lib/Object.h>
#include <gl/TexturedRect.h>
#include <gl/FramedTexture.h>

class GraphicItemCollection : public Object
{
public:
    TexturedRect StartGameItem;
    TexturedRect ExitItem;
    TexturedRect SelectTrackItem;
    TexturedRect RaceItem;
    TexturedRect BackItem;
    TexturedRect PauseItem;
    TexturedRect ResumeItem;
    TexturedRect StartMenuItem;
    TexturedRect Countdown1Item;
    TexturedRect Countdown2Item;
    TexturedRect Countdown3Item;
    TexturedRect GoItem;
    FramedTexture ExplosionTexture;

    void Init();
};
