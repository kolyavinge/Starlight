#pragma once

#include <lib/Object.h>
#include <calc/Vector3.h>
#include <audio/AudioData.h>

class AudioSample : public Object
{
    unsigned int _sourceId;

public:
    AudioSample();
    AudioSample(AudioData& data);
    ~AudioSample() override;

    void SetData(AudioData& data);
    void Play();
    void Pause();
    void Stop();
    bool IsPlayed();
    void SetGain(float gain);
    void SetPitch(float pitch);
    void SetPosition(Vector3& position);
    void SetVelocity(Vector3& velocity);
    void SetLooped(bool isLooped);
};
