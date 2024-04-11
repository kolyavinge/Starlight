#pragma once

#include <lib/di/ResolvingFactory.h>
#include <ui/Screen.h>
#include <audio/AudioSample.h>
#include <vox/common/AudioDataCollection.h>
#include <vox/ui/ScreenVox.h>

class RacePreparationVox : public ScreenVox
{
    AudioSample _countdownSample;

public:
    RacePreparationVox(AudioDataCollection& audioDataCollection);

    void Activate(Screen* prevScreen) override;
    void Deactivate() override;
    void Voice(Screen& screen) override;
};

class RacePreparationVoxResolvingFactory : public ResolvingFactory<RacePreparationVox>
{
public:
    RacePreparationVox* Make(Resolver& resolver) override;
};
