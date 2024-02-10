#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>

class AudioSampleException : public Exception {};

class AudioSample : public Object
{
    unsigned int _sourceId;
    unsigned int _bufferId;
    float _gain;
    float _pitch;

public:
    AudioSample();
    ~AudioSample();

    void Load(String filePath);
    void Play();
    void SetGain(float gain);
    void SetPitch(float pitch);

private:
    void InitSoundSource(String filePath);
};
