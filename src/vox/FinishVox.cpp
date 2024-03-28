#include <vox/FinishVox.h>

void FinishVox::Voice(Screen&)
{
}

FinishVox* FinishVoxResolvingFactory::Make(Resolver&)
{
    return new FinishVox();
}
