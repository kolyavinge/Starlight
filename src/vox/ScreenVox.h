#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>
#include <vox/SampleCollection.h>

class ScreenVox : public Object
{
public:
    virtual void Init(SampleCollection& sampleCollection) = 0;
    virtual void Activate(Screen* prevScreen);
    virtual void Deactivate();
    virtual void Voice(Screen& screen) = 0;
};
