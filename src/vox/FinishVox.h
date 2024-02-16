#pragma once

#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>

class FinishVox : public ScreenVox
{
public:
    void Init(SampleCollection& sampleCollection) override;
    void Voice(Screen& screen) override;
};
