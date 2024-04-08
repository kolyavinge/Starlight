#include <vox/VoxManager.h>

VoxManager::VoxManager(ScreenVoxCollection& voxCollection) :
    _voxCollection(voxCollection)
{
}

void VoxManager::Init()
{
    _voxCollection.Init();
}

ScreenVox& VoxManager::GetScreenVox(Screen& screen)
{
    return _voxCollection.GetScreenVox(screen);
}

VoxManager* VoxManagerResolvingFactory::Make(Resolver& resolver)
{
    return new VoxManager(resolver.Resolve<ScreenVoxCollection>());
}
