#include <openal/al.h>
#include <openal/alc.h>
#include <audio/ALFormat.h>
#include <audio/AudioSample.h>

AudioSample::AudioSample()
{
    _bufferId = 0;
    _sourceId = 0;
}

void AudioSample::Load(String filePath)
{
    _wavFile.Load(filePath);

    alGenSources(1, &_sourceId);
    alSourcef(_sourceId, AL_PITCH, 1.0f);
    alSourcef(_sourceId, AL_GAIN, 1.0f);
    alSource3f(_sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
    alSource3f(_sourceId, AL_VELOCITY, 0.0f, 0.0f, 0.0f);
    alSourcei(_sourceId, AL_LOOPING, AL_FALSE);
    alGenBuffers(1, &_bufferId);
    alSourcei(_sourceId, AL_BUFFER, _bufferId);
    alBufferData(
        _bufferId,
        ALFormat::Get(_wavFile.GetChannelsCount(), _wavFile.GetBitsPerSample()),
        _wavFile.GetSoundData(),
        _wavFile.GetSoundDataSizeBytes(),
        _wavFile.GetSampleRate());

    if (alGetError() != 0) throw AudioSampleException();
}

void AudioSample::Play()
{
    alSourcei(_sourceId, AL_BUFFER, _bufferId);
    alSourcePlay(_sourceId);
}
