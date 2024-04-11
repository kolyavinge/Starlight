#include <ui/RacePreparationScreen.h>
#include <vox/ui/RacePreparationVox.h>

RacePreparationVox::RacePreparationVox(
    AudioDataCollection& audioDataCollection,
    Race& race,
    ShipVox& shipVox) :
    _countdownSample(audioDataCollection.CountdownData),
    _race(race),
    _shipVox(shipVox)
{
    _engineIdleGain = 0.0f;
}

void RacePreparationVox::Activate(Screen*)
{
    _countdownSample.SetGain(0.3f);
    _countdownSample.SetPitch(1.0f);
    _engineIdleGain = 0.0f;
    _shipVox.SetEngineIdleGain(_engineIdleGain);
    _shipVox.Voice(_race.Player.CentralLine.Front, _race.AllShips);
}

void RacePreparationVox::Deactivate()
{
    // 3 2 1 GO!
    _countdownSample.SetPitch(1.25f);
    _countdownSample.Play();
    _shipVox.SetEngineIdleGain(1.0f);
}

void RacePreparationVox::Voice(Screen& screen)
{
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;
    if (racePreparationScreen.GetCountdownIteration() == 0)
    {
        _countdownSample.Play();
    }
    if (_engineIdleGain < 0.5f)
    {
        _shipVox.SetEngineIdleGain(_engineIdleGain);
        _engineIdleGain += 0.005f;
    }
}

RacePreparationVox* RacePreparationVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RacePreparationVox(
        resolver.Resolve<AudioDataCollection>(),
        resolver.Resolve<Race>(),
        resolver.Resolve<ShipVox>());
}
