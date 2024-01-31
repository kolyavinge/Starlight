#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/SampleCollection.h>

class ScreenVoxCollection : public Object
{
    SampleCollection _sampleCollection;
    Array<ScreenVox*, 4> _vox;

public:
    ScreenVoxCollection();
    ~ScreenVoxCollection();

    void Init();
    ScreenVox& GetScreenVox(Screen& screen);
};
