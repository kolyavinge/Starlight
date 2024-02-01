#include <lib/Exceptions.h>
#include <audio/ALFormat.h>

ALenum ALFormat::Get(short channelsCount, short bitsPerSample)
{
    if (channelsCount == 1 && bitsPerSample == 8)
    {
        return AL_FORMAT_MONO8;
    }
    else if (channelsCount == 1 && bitsPerSample == 16)
    {
        return AL_FORMAT_MONO16;
    }
    else if (channelsCount == 2 && bitsPerSample == 8)
    {
        return AL_FORMAT_STEREO8;
    }
    else if (channelsCount == 2 && bitsPerSample == 16)
    {
        return AL_FORMAT_STEREO16;
    }
    else
    {
        throw ArgumentException();
    }
}
