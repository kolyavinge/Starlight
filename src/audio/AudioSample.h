#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <audio/AudioData.h>

class AudioSample : public Object
{
    AudioData* _data;
    unsigned int _sourceId;
    float _gain;
    float _pitch;
    Vector3 _position;

public:
    AudioSample();
    AudioSample(AudioData& data);
    ~AudioSample() override;

    void SetData(AudioData& data);
    void Play();
    void SetGain(float gain);
    void SetPitch(float pitch);
    void SetPosition(Vector3& position);
};
