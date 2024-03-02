#include <model/Bullet.h>

Bullet::Bullet()
{
    Init();
}

void Bullet::Init()
{
    IsActive = false;
    Position.Set(0.0f, 0.0f, 0.0f);
    Direction.Set(0.0f, 0.0f, 0.0f);
    MovingDistance = 0.0f;
    TotalDistance = 0.0f;
}
