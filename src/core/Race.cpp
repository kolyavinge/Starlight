#include <lib/Debug.h>
#include <core/Race.h>

Race::Race(
    BorderUpdater& borderUpdater,
    RaceInitializer& raceInitializer,
    RacePositionUpdater& racePositionUpdater,
    RaceUpdater& raceUpdater,
    ShipController& playerController,
    ::Laps& laps) :
    _borderUpdater(borderUpdater),
    _raceInitializer(raceInitializer),
    _racePositionUpdater(racePositionUpdater),
    _raceUpdater(raceUpdater),
    PlayerController(playerController),
    Laps(laps),
    AllShips(EnemiesCount + 1)
{
    State = RaceState::Prepare;
    Track = nullptr;
    PlayerController.SetShip(Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        Enemies[i].InitForPlayer();
    }
    AllShips.Add(&Player);
    for (int i = 0; i < EnemiesCount; i++)
    {
        AllShips.Add(&Enemies[i]);
    }
    AllShipsSortedByPositions = AllShips;
}

void Race::Init(::Track& selectedTrack)
{
    State = RaceState::Prepare;
    Track = &selectedTrack;
    _raceInitializer.Init(Player, Enemies, AllShips, AllShipsSortedByPositions, *Track, PowerUps);
    for (int i = 0; i < AllShips.GetCount(); i++)
    {
        _borderUpdater.Update(*AllShips[i]);
    }
}

void Race::Start()
{
    Debug::Info(L"Start race");
    State = RaceState::Start;
    Laps.StartFirstLap();
}

void Race::Pause()
{
    Laps.StopTimer();
}

void Race::Resume()
{
    Laps.ResumeTimer();
}

void Race::Update()
{
    _raceUpdater.Update(
        State,
        Player,
        Enemies,
        AllShips,
        AllShipsSortedByPositions,
        PowerUps,
        *Track);
}

Race* RaceResolvingFactory::Make(Resolver& resolver)
{
    return new Race(
        resolver.Resolve<BorderUpdater>(),
        resolver.Resolve<RaceInitializer>(),
        resolver.Resolve<RacePositionUpdater>(),
        resolver.Resolve<RaceUpdater>(),
        resolver.Resolve<ShipController>(),
        resolver.Resolve<Laps>());
}
