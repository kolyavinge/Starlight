#pragma once

#include <lib/Object.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/ScreenVoxCollection.h>

class VoxManager : public Object
{
    ScreenVoxCollection _voxCollection;

public:
    void Init();
    ScreenVox& GetScreenVox(Screen& screen);

private:
    void InitAL();
};
