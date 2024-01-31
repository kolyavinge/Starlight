#pragma once

#include <lib/Object.h>
#include <audio/AudioSample.h>

class SampleCollection : public Object
{
public:
    AudioSample SelectMenuItem;

    void Init();
};
