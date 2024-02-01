#include <openal/al.h>
#include <openal/alc.h>
#include <audio/ALFormat.h>
#include <audio/AudioSample.h>

AudioSample::AudioSample()
{
    _sourceId = 0;
    _bufferId = 0;
}

AudioSample::~AudioSample()
{
    alDeleteSources(1, &_sourceId);
    alDeleteBuffers(1, &_bufferId);
}

void AudioSample::Load(String filePath)
{
    if (_sourceId != 0) throw AudioSampleException();
    if (_bufferId != 0) throw AudioSampleException();
    InitSoundSource(filePath);
    ALenum error = alGetError();
    if (error != AL_NO_ERROR) throw AudioSampleException();
    if (_sourceId == 0) throw AudioSampleException();
    if (_bufferId == 0) throw AudioSampleException();
}

void AudioSample::Play()
{
    alSourcei(_sourceId, AL_BUFFER, _bufferId);
    alSourcePlay(_sourceId);
}

void AudioSample::InitSoundSource(String filePath)
{
    _wavFile.Load(filePath);

    alGenBuffers(1, &_bufferId);
    alBufferData(
        _bufferId,
        ALFormat::Get(_wavFile.GetChannelsCount(), _wavFile.GetBitsPerSample()),
        _wavFile.GetSoundData(),
        _wavFile.GetSoundDataSizeBytes(),
        _wavFile.GetSampleRate());

    alGenSources(1, &_sourceId);
    alSourcei(_sourceId, AL_BUFFER, _bufferId);
    alSourcef(_sourceId, AL_PITCH, 1.0f);
    alSourcef(_sourceId, AL_GAIN, 1.0f);
    alSource3f(_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
    alSource3f(_sourceId, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSourcei(_sourceId, AL_LOOPING, AL_FALSE);
}
