#pragma once

#include <lib/Object.h>
#include <lib/List.h>
#include <model/Bullet.h>

class BulletCollisionResult : public Object
{
public:
    List<Bullet*> Bullets;

    BulletCollisionResult();

    void Init();
};
