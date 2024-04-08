#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <audio/AudioSample.h>
#include <vox/ScreenVox.h>
#include <vox/AudioDataCollection.h>

class RacePreparationVox : public ScreenVox
{
    AudioSample _countdownSample;

public:
    RacePreparationVox(AudioDataCollection& audioDataCollection);

    void Deactivate() override;
    void Voice(Screen& screen) override;
};

class RacePreparationVoxResolvingFactory : public ResolvingFactory<RacePreparationVox>
{
public:
    RacePreparationVox* Make(Resolver& resolver) override;
};
