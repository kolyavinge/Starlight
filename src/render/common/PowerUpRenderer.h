#pragma once

#include <lib/Object.h>
#include <lib/Collection.h>
#include <lib/di/ResolvingFactory.h>
#include <model/PowerUp.h>
#include <gl/Texture.h>
#include <render/common/GraphicItemCollection.h>

class PowerUpRenderer : public Object
{
    float _angleDegrees;
    Texture& _healthTexture;
    Texture& _machinegunTexture;
    Texture& _nitroTexture;

public:
    PowerUpRenderer(GraphicItemCollection& graphicItemCollection);

    void Render(Collection<PowerUp>& powerUps);
    void Update();

private:
    void BindTexture(PowerUp& powerUp);
    void RenderRect(PowerUp& powerUp);
};

class PowerUpRendererResolvingFactory : public ResolvingFactory<PowerUpRenderer>
{
public:
    PowerUpRenderer* Make(Resolver& resolver) override;
};
