#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <ai/ObstacleAvoidanceLogic.h>
#include <ai/SteeringLogic.h>
#include <ai/NitroActivationLogic.h>
#include <ai/WeaponActivationLogic.h>

class EnemyAI : public Object
{
    ObstacleAvoidanceLogic& _obstacleAvoidanceLogic;
    SteeringLogic& _steeringLogic;
    NitroActivationLogic& _nitroActivationLogic;
    WeaponActivationLogic& _weaponActivationLogic;

public:
    EnemyAI(
        ObstacleAvoidanceLogic& obstacleAvoidanceLogic,
        SteeringLogic& steeringLogic,
        NitroActivationLogic& nitroActivationLogic,
        WeaponActivationLogic& weaponActivationLogic);

    void ApplyFor(IArray<Ship>& enemies, IArray<Ship*>& allShips, Track& track);
    void ApplyFor(Ship& enemy, IArray<Ship*>& allShips, Track& track);
};

class EnemyAIResolvingFactory : public ResolvingFactory<EnemyAI>
{
public:
    EnemyAI* Make(Resolver& resolver) override;
};
