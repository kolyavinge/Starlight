#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <model/Ship.h>
#include <model/PowerUp.h>
#include <core/cm/PowerUpCollisionDetector.h>

class PowerUpCollisionProcessor : public Object
{
    PowerUpCollisionDetector _powerUpCollisionDetector;

public:
    void ProcessPowerUpsCollisions(Ship& ship, IArray<PowerUp>& powerUps);

private:
    bool ProcessPowerUp(Ship& ship, PowerUp& powerUp);
};
