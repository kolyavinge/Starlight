#pragma once

#include <openal/al.h>

class ALFormat
{
public:
    static ALenum Get(short channelsCount, short bitsPerSample);
};
