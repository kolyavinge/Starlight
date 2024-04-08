#include <openal/al.h>
#include <audio/ALFormat.h>
#include <audio/WavFile.h>
#include <audio/AudioData.h>

AudioData::AudioData()
{
    _bufferId = 0;
}

AudioData::~AudioData()
{
    alDeleteBuffers(1, &_bufferId);
}

void AudioData::LoadFromFile(String filePath)
{
    if (_bufferId != 0) throw AudioException();

    WavFile wavFile(filePath);

    alGenBuffers(1, &_bufferId);
    alBufferData(
        _bufferId,
        ALFormat::Get(wavFile.GetChannelsCount(), wavFile.GetBitsPerSample()),
        wavFile.GetSoundData(),
        wavFile.GetSoundDataSizeBytes(),
        wavFile.GetSampleRate());

    if (_bufferId == 0) throw AudioException();
}

unsigned int AudioData::GetBufferId()
{
    return _bufferId;
}
