#include <model/Track.h>
#include <core/Constants.h>
#include <anx/GraphicResources.h>
#include <gl/opengl.h>
#include <render/common/RenderConstants.h>
#include <render/common/TrackThumbnailGridRenderer.h>

TrackThumbnailGridRenderer::TrackThumbnailGridRenderer(
    TrackThumbnailRenderer& trackThumbnailRenderer) :
    _trackThumbnailRenderer(trackThumbnailRenderer)
{
    _selectionRect.Load(GraphicResources::GetTrackSelectionRectFilePath());
}

void TrackThumbnailGridRenderer::Render(TrackSelectorScreen& screen)
{
    float totalWidth = (float)screen.GetTrackGridColsCount() * TrackThumbnail::Width;
    float totalHeight = (float)screen.GetTrackGridRowsCount() * TrackThumbnail::Height;
    float centerX = (Constants::ScreenWidth - totalWidth) / 2.0f;
    float centerY = (Constants::ScreenHeight - totalHeight) / 2.0f;
    int rendererIndex = 0;
    for (int row = 0; row < screen.GetTrackGridRowsCount(); row++)
    {
        for (int col = 0; col < screen.GetTrackGridColsCount(); col++)
        {
            Track& track = screen.GetTrackByCell(row, col);
            bool isSelected = screen.GetSelectedTrack().Equals(track);
            glPushMatrix();
            glTranslatef(
                centerX + (float)col * TrackThumbnail::Width,
                centerY + (float)(screen.GetTrackGridColsCount() - row - 1) * TrackThumbnail::Height,
                0.0f);
            float alpha = isSelected ? 1.0f : 0.4f;
            glColor4f(RenderConstants::TextColor, RenderConstants::TextColor, RenderConstants::TextColor, alpha);
            _trackThumbnailRenderer.Render(track, _rotateDegrees[rendererIndex]);
            if (isSelected) _rotateDegrees[rendererIndex] -= 1.0f;
            rendererIndex++;
            if (isSelected && screen.IsTrackSelectionActive())
            {
                _selectedItemColor.SetColorForSelectedItem(true);
                _selectionRect.Render();
            }
            glPopMatrix();
        }
    }
    _selectedItemColor.Update();
}

TrackThumbnailGridRenderer* TrackThumbnailGridRendererResolvingFactory::Make(Resolver& resolver)
{
    return new TrackThumbnailGridRenderer(resolver.Resolve<TrackThumbnailRenderer>());
}
