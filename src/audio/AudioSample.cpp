#include <openal/al.h>
#include <audio/AudioSample.h>

AudioSample::AudioSample()
{
    _sourceId = 0;
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
    alGenSources(1, &_sourceId);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) throw AudioException();
    if (_sourceId == 0) throw AudioException();
    alSourcei(_sourceId, AL_BUFFER, data.GetBufferId());
}

void AudioSample::Play()
{
    alSourcePlay(_sourceId);
}

void AudioSample::Pause()
{
    alSourcePause(_sourceId);
}

void AudioSample::Stop()
{
    alSourceStop(_sourceId);
}

bool AudioSample::IsPlayed()
{
    int state;
    alGetSourcei(_sourceId, AL_SOURCE_STATE, &state);

    return state == AL_PLAYING;
}

void AudioSample::SetGain(float gain)
{
    alSourcef(_sourceId, AL_GAIN, gain);
}

void AudioSample::SetPitch(float pitch)
{
    alSourcef(_sourceId, AL_PITCH, pitch);
}

void AudioSample::SetPosition(Vector3& position)
{
    alSource3f(_sourceId, AL_POSITION, position.X, position.Y, position.Z);
}

void AudioSample::SetVelocity(Vector3& velocity)
{
    alSource3f(_sourceId, AL_VELOCITY, velocity.X, velocity.Y, velocity.Z);
}

void AudioSample::SetLooped(bool isLooped)
{
    alSourcei(_sourceId, AL_LOOPING, isLooped ? AL_TRUE : AL_FALSE);
}
