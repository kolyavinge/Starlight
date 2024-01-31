#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class AudioSample : public Object
{
public:
    void Load(String filePath);
    void Play();
};
