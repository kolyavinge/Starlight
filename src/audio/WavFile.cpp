#include <lib/File.h>
#include <audio/WavFile.h>

WavFile::WavFile()
{
    _fileBytes = nullptr;
    _wavData = nullptr;
}

WavFile::~WavFile()
{
    if (_fileBytes != nullptr)
    {
        delete _fileBytes;
    }
}

void WavFile::Load(String filePath)
{
    int fileSizeBytes = (int)File::GetFileSizeBytes(filePath.GetWCharBuf());
    _fileBytes = new char[fileSizeBytes];
    File::ReadAllBytes(filePath.GetWCharBuf(), fileSizeBytes, _fileBytes);
    _wavData = (WavData*)_fileBytes;
}

short WavFile::GetChannelsCount()
{
    return _wavData->ChannelsCount;
}

int WavFile::GetSampleRate()
{
    return _wavData->SampleRate;
}

short WavFile::GetBitsPerSample()
{
    return _wavData->BitsPerSample;
}

void* WavFile::GetSoundData()
{
    return _wavData->SoundData;
}

int WavFile::GetSoundDataSizeBytes()
{
    return _wavData->Subchunk2Size;
}
