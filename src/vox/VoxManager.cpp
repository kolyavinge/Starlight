#include <openal/al.h>
#include <openal/alc.h>
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
    ALCdevice* device = alcOpenDevice(nullptr);
    if (!device) throw VoxManagerException();
    ALCcontext* context = alcCreateContext(device, nullptr);
    if (!alcMakeContextCurrent(context)) throw VoxManagerException();
}
