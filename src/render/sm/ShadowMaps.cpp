#include <render/sm/ShadowMaps.h>

ShadowMaps* ShadowMapsResolvingFactory::Make(Resolver&)
{
    return new ShadowMaps();
}
