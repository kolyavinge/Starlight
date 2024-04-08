#include <openal/al.h>
#include <audio/AudioSample.h>

AudioSample::AudioSample()
{
    _data = nullptr;
    _sourceId = 0;
    _gain = 1.0f;
    _pitch = 1.0f;
}

AudioSample::AudioSample(AudioData& data) :
    AudioSample()
{
    SetData(data);
}

AudioSample::~AudioSample()
{
    alDeleteSources(1, &_sourceId);
}

void AudioSample::SetData(AudioData& data)
{
    _data = &data;
    alGenSources(1, &_sourceId);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) throw AudioException();
    if (_sourceId == 0) throw AudioException();
}

void AudioSample::Play()
{
    alSourcei(_sourceId, AL_BUFFER, _data->GetBufferId());
    alSourcef(_sourceId, AL_PITCH, _pitch);
    alSourcef(_sourceId, AL_GAIN, _gain);
    alSource3f(_sourceId, AL_POSITION, _position.X, _position.Y, _position.Z);
    alSource3f(_sourceId, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSourcei(_sourceId, AL_LOOPING, AL_FALSE);
    alSourcePlay(_sourceId);
}

void AudioSample::SetGain(float gain)
{
    _gain = gain;
}

void AudioSample::SetPitch(float pitch)
{
    _pitch = pitch;
}

void AudioSample::SetPosition(Vector3& position)
{
    _position = position;
}
