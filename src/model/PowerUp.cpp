#include <model/PowerUp.h>

PowerUp::PowerUp()
{
    IsActive = false;
    Kind = PowerUpKind::Health;
    Value = 0.0f;
}
