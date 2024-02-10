#pragma once

#include <lib/Object.h>
#include <audio/AudioSample.h>

class SampleCollection : public Object
{
public:
    AudioSample SelectMenuItemSample;
    AudioSample CountdownSample;

    void Init();
};
