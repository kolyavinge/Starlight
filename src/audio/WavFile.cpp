#include <lib/Assert.h>
#include <lib/File.h>
#include <audio/WavFile.h>

WavFile::WavFile()
{
    Assert::True(sizeof(WavData) == 44);
    _fileBytes = nullptr;
    _wavData = nullptr;
    _soundData = nullptr;
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
    int readedFileSizeBytes = File::ReadAllBytes(filePath.GetWCharBuf(), fileSizeBytes, _fileBytes);
    Assert::True(fileSizeBytes == readedFileSizeBytes);
    _wavData = (WavData*)_fileBytes;
    _soundData = _fileBytes + sizeof(WavData);
}

short WavFile::GetChannelsCount()
{
    return _wavData->ChannelsCount;
}

int WavFile::GetSampleRate()
{
    return _wavData->SampleRate;
}

int WavFile::GetByteRate()
{
    return _wavData->ByteRate;
}

short WavFile::GetBitsPerSample()
{
    return _wavData->BitsPerSample;
}

void* WavFile::GetSoundData()
{
    return _soundData;
}

int WavFile::GetSoundDataSizeBytes()
{
    return _wavData->Subchunk2Size;
}
