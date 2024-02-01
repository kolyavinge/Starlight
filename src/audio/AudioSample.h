#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>
#include <audio/WavFile.h>

class AudioSampleException : public Exception {};

class AudioSample : public Object
{
    WavFile _wavFile;
    unsigned int _sourceId;
    unsigned int _bufferId;

public:
    AudioSample();

    void Load(String filePath);
    void Play();
};
