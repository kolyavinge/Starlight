#include <vox/VoxManager.h>

void VoxManager::Init()
{
    InitAL();
    _voxCollection.Init();
}

ScreenVox& VoxManager::GetScreenVox(Screen& screen)
{
    return _voxCollection.GetScreenVox(screen);
}

void VoxManager::InitAL()
{
}
