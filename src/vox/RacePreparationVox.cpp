#include <ui/RacePreparationScreen.h>
#include <vox/RacePreparationVox.h>

RacePreparationVox::RacePreparationVox()
{
    _countdownSample = nullptr;
}

void RacePreparationVox::Init(SampleCollection& sampleCollection)
{
    _countdownSample = &sampleCollection.CountdownSample;
}

void RacePreparationVox::Voice(Screen& screen)
{
    RacePreparationScreen& racePreparationScreen = (RacePreparationScreen&)screen;
    if (racePreparationScreen.GetCountdownIteration() == 0)
    {
        _countdownSample->Play();
    }
}
