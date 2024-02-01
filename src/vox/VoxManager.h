#pragma once

#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <ui/Screen.h>
#include <vox/ScreenVox.h>
#include <vox/ScreenVoxCollection.h>

class VoxManagerException : public Exception { };

class VoxManager : public Object
{
    ScreenVoxCollection _voxCollection;

public:
    void Init();
    ScreenVox& GetScreenVox(Screen& screen);

private:
    void InitAL();
};
