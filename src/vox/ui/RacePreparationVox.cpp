#include <ui/RacePreparationScreen.h>
#include <vox/ui/RacePreparationVox.h>

RacePreparationVox::RacePreparationVox(AudioDataCollection& audioDataCollection) :
    _countdownSample(audioDataCollection.CountdownData)
{
}

void RacePreparationVox::Activate(Screen*)
{
    _countdownSample.SetGain(0.3f);
    _countdownSample.SetPitch(1.0f);
}

void RacePreparationVox::Deactivate()
{
    // 3 2 1 GO!
    _countdownSample.SetPitch(1.25f);
    _countdownSample.Play();
}

void RacePreparationVox::Voice(Screen& screen)
{
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;
    if (racePreparationScreen.GetCountdownIteration() == 0)
    {
        _countdownSample.Play();
    }
}

RacePreparationVox* RacePreparationVoxResolvingFactory::Make(Resolver& resolver)
{
    return new RacePreparationVox(resolver.Resolve<AudioDataCollection>());
}
