#pragma once

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
    void Voice(Screen& screen) override;
};
