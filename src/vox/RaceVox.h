#pragma once

#include <audio/AudioSample.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>

class RaceVox : public ScreenVox
{
    AudioSample* _weaponFireSample;
    AudioSample* _metalHitSample;
    AudioSample* _explosionSample;

public:
    RaceVox();

    void Init(SampleCollection& sampleCollection) override;
    void Voice(Screen& screen) override;
};
