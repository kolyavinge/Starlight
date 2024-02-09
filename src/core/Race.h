#pragma once

#include <lib/Object.h>
#include <model/Ship.h>
#include <model/Track.h>
#include <core/ShipController.h>
#include <core/RaceUpdater.h>
#include <core/Camera.h>
#include <core/Laps.h>

class Race : public Object
{
    RaceUpdater& _raceUpdater;

public:
    Ship Player;
    Track* Track;
    ShipController PlayerController;
    Camera Camera;
    Laps Laps;

    Race(
        RaceUpdater& raceUpdater);

    void Init(::Track& selectedTrack);
    void Start();
    void Update();
};
