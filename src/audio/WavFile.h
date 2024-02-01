#pragma once

#include <lib/Object.h>
#include <lib/String.h>

class WavFile : public Object
{
    struct WavData
    {
        char ChunkID[4];
        int ChunkSize;
        char Format[4];
        char Subchunk1ID[4];
        int Subchunk1Size;
        short AudioFormat;
        short ChannelsCount;
        int SampleRate;
        int ByteRate;
        short BlockAlign;
        short BitsPerSample;
        char Subchunk2ID[4];
        int Subchunk2Size;
    };

    char* _fileBytes;
    WavData* _wavData;
    void* _soundData;

public:
    WavFile();
    ~WavFile();

    void Load(String filePath);

    short GetChannelsCount();
    int GetSampleRate();
    int GetByteRate();
    short GetBitsPerSample();
    void* GetSoundData();
    int GetSoundDataSizeBytes();
};
