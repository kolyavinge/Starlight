#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Texture.h>
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
    Texture PowerUpHealthTexture;
    Texture PowerUpMachinegunTexture;
    Texture PowerUpNitroTexture;
    FramedTexture ExplosionTexture;

    void Init();
};

class GraphicItemCollectionResolvingFactory : public ResolvingFactory<GraphicItemCollection>
{
public:
    GraphicItemCollection* Make(Resolver& resolver) override;
};
