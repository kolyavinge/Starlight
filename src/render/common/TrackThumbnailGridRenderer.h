#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <lib/di/ResolvingFactory.h>
#include <ui/TrackSelectorScreen.h>
#include <gl/TexturedRect.h>
#include <render/common/TrackThumbnailRenderer.h>
#include <render/ui/SelectedItemColor.h>

class TrackThumbnailGridRenderer : public Object
{
    TrackThumbnailRenderer& _trackThumbnailRenderer;
    Array<float, 4> _rotateDegrees;
    TexturedRect _selectionRect;
    SelectedItemColor _selectedItemColor;

public:
    TrackThumbnailGridRenderer(TrackThumbnailRenderer& trackThumbnailRenderer);

    void Init();
    void Render(TrackSelectorScreen& screen);
};

class TrackThumbnailGridRendererResolvingFactory : public ResolvingFactory<TrackThumbnailGridRenderer>
{
public:
    TrackThumbnailGridRenderer* Make(Resolver& resolver) override;
};
