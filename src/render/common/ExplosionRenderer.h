#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <gl/FramedTexture.h>
#include <gl/AnimatedTexturedRect.h>

class ExplosionRenderer : public Object
{
    FramedTexture* _explosionTexture;
    List<AnimatedTexturedRect> _animations;
    List<Vector3> _positions;

public:
    ExplosionRenderer();

    void Init(FramedTexture& explosionTexture);
    void Render(IArray<Ship*>& allShips);

private:
    void RenderAnimations();
    void MakeNewAnimations(IArray<Ship*>& allShips);
    bool AllAnimationsInnactive();
};
