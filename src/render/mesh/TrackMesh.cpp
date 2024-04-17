#include <lib/Point2.h>
#include <lib/ArrayIndexGenerator.h>
#include <gl/Face.h>
#include <anx/GraphicResources.h>
#include <render/mesh/TrackMesh.h>

void TrackMesh::MakeGroundMesh(Track& track, Mesh& mesh)
{
    const int segmentPointStep = 20;
    const int segmentsCount = 4;

    mesh.VertexCoords.PrepareEnoughCapacity(track.PointsCount);
    mesh.NormalCoords.PrepareEnoughCapacity(track.PointsCount);
    mesh.TextureCoords.PrepareEnoughCapacity(track.PointsCount);
    mesh.Faces.PrepareEnoughCapacity(track.PointsCount);

    MakeGroundSegment(track, 0, track.StartFinishLineIndex, segmentPointStep, segmentsCount, 0.0f, mesh);
    MakeGroundSegment(track, track.StartFinishLineIndex, track.StartFinishLineIndex + 2 * segmentsCount * segmentPointStep, segmentPointStep, segmentsCount, 0.5f, mesh);
    MakeGroundSegment(track, track.StartFinishLineIndex + 2 * segmentsCount * segmentPointStep, track.PointsCount, segmentPointStep, segmentsCount, 0.0f, mesh);

    mesh.Textures.AddNew().Load(GraphicResources::GetTrackGround1TextureFilePath());
}

void TrackMesh::MakeEdgeMesh(Track& track, Mesh& mesh)
{

    mesh.Textures.AddNew().Load(GraphicResources::GetTrackEdgeTextureFilePath());
}

void TrackMesh::MakeGroundSegment(Track& track, int startPointIndex, int endPointIndex, int segmentPointStep, int segmentsCount, float startTextureY, Mesh& mesh)
{
    const float textureStep = 0.5f / (float)segmentsCount;
    int iter = 0;
    ArrayIndexGenerator pointIndexGenerator(startPointIndex, endPointIndex, segmentPointStep);
    pointIndexGenerator.MoveNext(); // skip first
    while (pointIndexGenerator.MoveNext())
    {
        const int vertexIndex = mesh.VertexCoords.GetCount();
        int prevIndex = pointIndexGenerator.GetPrevIndex();
        int currentIndex = pointIndexGenerator.GetCurrentIndex();
        mesh.VertexCoords.Add(track.OutsidePoints[prevIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[prevIndex]);
        mesh.VertexCoords.Add(track.OutsidePoints[currentIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[currentIndex]);
        mesh.NormalCoords.Add(track.Normals[prevIndex]);
        mesh.NormalCoords.Add(track.Normals[prevIndex]);
        mesh.NormalCoords.Add(track.Normals[currentIndex]);
        mesh.NormalCoords.Add(track.Normals[currentIndex]);
        const float textureY = startTextureY + (float)(iter % segmentsCount) * textureStep;
        mesh.TextureCoords.Add(Point2(0.0f, textureY));
        mesh.TextureCoords.Add(Point2(1.0f, textureY));
        mesh.TextureCoords.Add(Point2(0.0f, textureY + textureStep));
        mesh.TextureCoords.Add(Point2(1.0f, textureY + textureStep));
        mesh.Faces.Add(Face(vertexIndex, vertexIndex + 1, vertexIndex + 2));
        mesh.Faces.Add(Face(vertexIndex + 1, vertexIndex + 2, vertexIndex + 3));
        iter++;
    }
}

TrackMesh* TrackMeshResolvingFactory::Make(Resolver&)
{
    return new TrackMesh();
}
