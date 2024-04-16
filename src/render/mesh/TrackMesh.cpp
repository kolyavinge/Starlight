#include <lib/Point2.h>
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

    MakeGroundSegment(track, 0, track.StartFinishLineIndex, segmentPointStep, segmentsCount, mesh);
    MakeGroundSegment(track, track.StartFinishLineIndex, track.StartFinishLineIndex + 2 * segmentsCount * segmentPointStep, segmentPointStep, segmentsCount, mesh);
    MakeGroundSegment(track, track.StartFinishLineIndex + 2 * segmentsCount * segmentPointStep, track.PointsCount, segmentPointStep, segmentsCount, mesh);

    mesh.Textures.AddNew().Load(GraphicResources::GetTrackGround1TextureFilePath());
    mesh.Textures.AddNew().Load(GraphicResources::GetTrackGroundFinishTextureFilePath());
    mesh.Textures.AddNew().Load(GraphicResources::GetTrackEdgeTextureFilePath());
}

void TrackMesh::MakeEdgeMesh(Track& track, Mesh& mesh)
{

}

void TrackMesh::MakeGroundSegment(Track& track, int startPointIndex, int endPointIndex, int segmentPointStep, int segmentsCount, Mesh& mesh)
{
    const float textureStep = 1.0f / (float)segmentsCount;

    int iter = 0;
    int vertexIndex = mesh.VertexCoords.GetCount();
    for (int pointIndex = startPointIndex; pointIndex < endPointIndex; pointIndex += segmentPointStep, iter++)
    {
        const float textureY = (float)(iter % segmentsCount) * textureStep;
        mesh.VertexCoords.Add(track.OutsidePoints[pointIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[pointIndex]);
        mesh.NormalCoords.Add(track.Normals[pointIndex]);
        mesh.NormalCoords.Add(track.Normals[pointIndex]);
        mesh.TextureCoords.Add(Point2(0.0f, textureY));
        mesh.TextureCoords.Add(Point2(1.0f, textureY));
        mesh.Faces.Add(Face(vertexIndex, vertexIndex + 1, vertexIndex + 2));
        mesh.Faces.Add(Face(vertexIndex + 1, vertexIndex + 2, vertexIndex + 3));
        vertexIndex += 2;
    }

    if ((endPointIndex % segmentPointStep) != 0)
    {
        const float textureY = (float)(iter % segmentsCount) * textureStep;
        mesh.VertexCoords.Add(track.OutsidePoints[endPointIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[endPointIndex]);
        mesh.NormalCoords.Add(track.Normals[endPointIndex]);
        mesh.NormalCoords.Add(track.Normals[endPointIndex]);
        mesh.TextureCoords.Add(Point2(0.0f, textureY));
        mesh.TextureCoords.Add(Point2(1.0f, textureY));
    }
}

TrackMesh* TrackMeshResolvingFactory::Make(Resolver&)
{
    return new TrackMesh();
}
