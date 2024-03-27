#pragma once

#include <lib/Object.h>
#include <lib/IArray.h>
#include <lib/List.h>
#include <lib/di/ResolvingFactory.h>
#include <calc/Vector3.h>
#include <model/Ship.h>
#include <gl/FramedTexture.h>
#include <gl/AnimatedTexturedRect.h>
#include <render/common/GraphicItemCollection.h>

class ExplosionRenderer : public Object
{
    FramedTexture& _explosionTexture;
    List<AnimatedTexturedRect> _animations;
    List<Vector3> _positions;
    List<float> _radians;
    List<Vector3> _pivots;

public:
    ExplosionRenderer(GraphicItemCollection& graphicItemCollection);

    void Init();
    void Render(Ship& player, IArray<Ship*>& allShips);

private:
    void RenderAnimations();
    void MakeNewAnimations(Ship& player, IArray<Ship*>& allShips);
    bool AllAnimationsInnactive();
    void ClearAnimations();
};

class ExplosionRendererResolvingFactory : public ResolvingFactory<ExplosionRenderer>
{
public:
    ExplosionRenderer* Make(Resolver& resolver) override;
};
