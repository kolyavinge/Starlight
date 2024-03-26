#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <model/PowerUp.h>
#include <core/RaceState.h>
#include <core/ShipController.h>
#include <core/RaceUpdater.h>
#include <core/Camera.h>
#include <core/Laps.h>
#include <ai/EnemyAI.h>

class Race : public Object
{
    RaceUpdater _raceUpdater;

public:
    inline static const int EnemiesCount = 3;

    RaceState State;
    Ship Player;
    Array<Ship, EnemiesCount> Enemies;
    List<Ship*> AllShips;
    List<PowerUp> PowerUps;
    Track* Track;
    ShipController PlayerController;
    Camera Camera;
    Laps Laps;
    EnemyAI EnemyAI;

    Race();

    void Init(::Track& selectedTrack);
    void Start();
    void Pause();
    void Resume();
    void Update();
};

class RaceResolvingFactory : public ResolvingFactory<Race>
{
public:
    Race* Make(Resolver& resolver) override;
};
