#include <audio/ALFormat.h>

ALenum ALFormat::Get(short channelsCount, short bitsPerSample)
{
    bool stereo = (channelsCount > 1);

    switch (bitsPerSample) {
    case 16:
        if (stereo)
            return AL_FORMAT_STEREO16;
        else
            return AL_FORMAT_MONO16;
    case 8:
        if (stereo)
            return AL_FORMAT_STEREO8;
        else
            return AL_FORMAT_MONO8;
    }

    return -1;
}
