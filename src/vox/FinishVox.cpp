#include <vox/FinishVox.h>

void FinishVox::Init(SampleCollection&)
{
}

void FinishVox::Voice(Screen&)
{
}

FinishVox* FinishVoxResolvingFactory::Make(Resolver&)
{
    return new FinishVox();
}
