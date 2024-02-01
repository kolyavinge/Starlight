#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class WavFile : public Object
{
    struct WavData
    {
        int ChunkID;
        int ChunkSize;
        int Format;
        int Subchunk1ID;
        int Subchunk1Size;
        short AudioFormat;
        short ChannelsCount;
        int SampleRate;
        int ByteRate;
        short BlockAlign;
        short BitsPerSample;
        int Subchunk2ID;
        int Subchunk2Size;
        void* SoundData;
    };

    char* _fileBytes;
    WavData* _wavData;
    int _soundDataSize;

public:
    WavFile();
    ~WavFile();

    void Load(String filePath);

    short GetChannelsCount();
    int GetSampleRate();
    short GetBitsPerSample();
    void* GetSoundData();
    int GetSoundDataSizeBytes();
};
