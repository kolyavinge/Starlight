#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <audio/AudioSample.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>

class RacePreparationVox : public ScreenVox
{
    AudioSample* _countdownSample;

public:
    RacePreparationVox();

    void Init(SampleCollection& sampleCollection) override;
    void Deactivate() override;
    void Voice(Screen& screen) override;
};

class RacePreparationVoxResolvingFactory : public ResolvingFactory<RacePreparationVox>
{
public:
    RacePreparationVox* Make(Resolver& resolver) override;
};
