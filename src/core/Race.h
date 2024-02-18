#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <model/Ship.h>
#include <model/Track.h>
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
    inline static const int EnemiesCount = 1;

    RaceState State;
    Ship Player;
    List<Ship> Enemies;
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
