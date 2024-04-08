#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>

class AudioException : public Exception {};

class AudioData : public Object
{
    unsigned int _bufferId;

public:
    AudioData();
    ~AudioData() override;

    void LoadFromFile(String filePath);
    unsigned int GetBufferId();
};
