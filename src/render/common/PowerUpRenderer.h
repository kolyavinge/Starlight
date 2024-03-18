#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/PowerUp.h>
#include <gl/Texture.h>

class PowerUpRenderer : public Object
{
    float _angleDegrees;
    Texture* _healthTexture;
    Texture* _machinegunTexture;

public:
    PowerUpRenderer();

    void Init(Texture& healthTexture, Texture& machinegunTexture);
    void Render(IArray<PowerUp>& powerUps);

private:
    void BindTexture(PowerUp& powerUp);
    void RenderRect(PowerUp& powerUp);
};
