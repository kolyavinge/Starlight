#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <core/Race.h>
#include <render/common/BackgroundRenderer.h>
#include <render/common/ShipsRenderer.h>
#include <render/common/TrackRenderer.h>
#include <render/common/BulletsRenderer.h>
#include <render/common/PowerUpRenderer.h>
#include <render/common/ExplosionRenderer.h>

class MirrorViewRenderer : public Object
{
    const float _mirrorWidth;
    const float _mirrorHeight;
    const unsigned int _resolutionWidth;
    const unsigned int _resolutionHeight;
    unsigned int _fboId;
    unsigned int _textureId;
    Race& _race;
    BackgroundRenderer& _backgroundRenderer;
    ShipsRenderer& _shipsRenderer;
    TrackRenderer& _trackRenderer;
    BulletsRenderer& _bulletsRenderer;
    PowerUpRenderer& _powerUpRenderer;
    ExplosionRenderer& _explosionRenderer;

public:
    MirrorViewRenderer(
        Race& race,
        BackgroundRenderer& backgroundRenderer,
        ShipsRenderer& shipsRenderer,
        TrackRenderer& trackRenderer,
        BulletsRenderer& bulletsRenderer,
        PowerUpRenderer& powerUpRenderer,
        ExplosionRenderer& explosionRenderer);

    ~MirrorViewRenderer() override;

    void Render();

private:
    void UpdateTexture();
    void RenderTexture();
    void RenderBorder();
    void InitFBO();
};

class MirrorViewRendererResolvingFactory : public ResolvingFactory<MirrorViewRenderer>
{
public:
    MirrorViewRenderer* Make(Resolver& resolver);
};
