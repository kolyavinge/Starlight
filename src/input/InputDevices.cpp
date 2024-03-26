#include <input/InputDevices.h>

InputDevices* InputDevicesResolvingFactory::Make(Resolver&)
{
    return new InputDevices();
}
