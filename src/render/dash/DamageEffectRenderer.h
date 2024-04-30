#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <gl/Texture.h>
#include <render/common/GraphicItemCollection.h>

class DamageEffectRenderer : public Object
{
    Texture& _damageEffectTexture;
    float _alpha;

public:
    DamageEffectRenderer(GraphicItemCollection& graphicItemCollection);

    void Init();
    void Update(Ship& player);
    void Render();
};

class DamageEffectRendererResolvingFactory : public ResolvingFactory<DamageEffectRenderer>
{
public:
    DamageEffectRenderer* Make(Resolver& resolver);
};
