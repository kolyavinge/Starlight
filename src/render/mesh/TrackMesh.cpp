#include <lib/Utils.h>
#include <lib/Point2.h>
#include <lib/ArrayIndexGenerator.h>
#include <calc/Vector3.h>
#include <model/TrackEdge.h>
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

    SetCounterClockwiseFacing(track, mesh);

    mesh.Textures.AddNew().Load(GraphicResources::GetTrackGround1TextureFilePath());
}

void TrackMesh::MakeEdgeMesh(Track& track, Mesh& mesh)
{
    mesh.VertexCoords.PrepareEnoughCapacity(track.EdgesCount * TrackEdgeMaxPoints);
    mesh.NormalCoords.PrepareEnoughCapacity(track.EdgesCount * TrackEdgeMaxPoints);
    mesh.TextureCoords.PrepareEnoughCapacity(track.EdgesCount * TrackEdgeMaxPoints);
    mesh.Faces.PrepareEnoughCapacity(track.EdgesCount * TrackEdgeMaxPoints);

    MakeEdgeMesh(track.EdgesCount, track.InsideEdges, track.EdgeNormals, mesh);
    MakeEdgeMesh(track.EdgesCount, track.OutsideEdges, track.EdgeNormals, mesh);

    mesh.Textures.AddNew().Load(GraphicResources::GetTrackEdgeTextureFilePath());
}

void TrackMesh::MakeGroundSegment(Track& track, int startPointIndex, int endPointIndex, int segmentPointStep, int segmentsCount, float startTextureY, Mesh& mesh)
{
    const float fullTextureStep = 0.5f / (float)segmentsCount;
    int iter = 0;
    ArrayIndexGenerator pointIndexGenerator(startPointIndex, endPointIndex, segmentPointStep);
    pointIndexGenerator.MoveNext(); // skip first
    while (pointIndexGenerator.MoveNext())
    {
        const int vertexIndex = mesh.VertexCoords.GetCount();
        const int prevIndex = pointIndexGenerator.GetPrevIndex();
        const int currentIndex = pointIndexGenerator.GetCurrentIndex();
        mesh.VertexCoords.Add(track.OutsidePoints[prevIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[prevIndex]);
        mesh.VertexCoords.Add(track.OutsidePoints[currentIndex]);
        mesh.VertexCoords.Add(track.InsidePoints[currentIndex]);
        mesh.NormalCoords.Add(track.Normals[prevIndex]);
        mesh.NormalCoords.Add(track.Normals[prevIndex]);
        mesh.NormalCoords.Add(track.Normals[currentIndex]);
        mesh.NormalCoords.Add(track.Normals[currentIndex]);
        const float textureY = startTextureY + (float)(iter % segmentsCount) * fullTextureStep;
        const float textureStep = fullTextureStep * (float)(currentIndex - prevIndex) / (float)segmentPointStep;
        mesh.TextureCoords.Add(Point2(0.0f, textureY));
        mesh.TextureCoords.Add(Point2(1.0f, textureY));
        mesh.TextureCoords.Add(Point2(0.0f, textureY + textureStep));
        mesh.TextureCoords.Add(Point2(1.0f, textureY + textureStep));
        mesh.Faces.Add(Face(vertexIndex, vertexIndex + 1, vertexIndex + 2));
        mesh.Faces.Add(Face(vertexIndex + 1, vertexIndex + 3, vertexIndex + 2));
        iter++;
    }
}

void TrackMesh::SetCounterClockwiseFacing(Track& track, Mesh& mesh)
{
    Vector3 straightDirection(track.InsidePoints[1]);
    straightDirection.Sub(track.InsidePoints[0]);

    Vector3 vertexDirection(mesh.VertexCoords[0]);
    vertexDirection.Sub(mesh.VertexCoords[1]);

    vertexDirection.VectorProduct(straightDirection);
    if (vertexDirection.Z > 0.0f)
    {
        for (int i = 0; i < mesh.Faces.GetCount(); i++)
        {
            Utils::Swap(mesh.Faces[i].i0, mesh.Faces[i].i2);
        }
    }
}

void TrackMesh::MakeEdgeMesh(int edgesCount, TrackEdges& edges, TrackEdges& normals, Mesh& mesh)
{
    const float textureStep = 1.0f / (float)TrackEdgeMaxPoints;
    for (int edgeIndex = 0; edgeIndex < edgesCount; edgeIndex++)
    {
        TrackEdge& edge = edges[edgeIndex];
        TrackEdge& nextEdge = edges[edgeIndex + 1];
        TrackEdge& normal = normals[edgeIndex];
        TrackEdge& nextNormal = normals[edgeIndex + 1];

        for (int pointIndex = 0; pointIndex < TrackEdgeMaxPoints; pointIndex++)
        {
            const int vertexIndex = mesh.VertexCoords.GetCount();
            mesh.VertexCoords.Add(edge.Points[pointIndex]);
            mesh.VertexCoords.Add(nextEdge.Points[pointIndex]);
            mesh.NormalCoords.Add(normal.Points[pointIndex]);
            mesh.NormalCoords.Add(nextNormal.Points[pointIndex]);
            mesh.TextureCoords.Add(Point2((float)pointIndex * textureStep, 0.0f));
            mesh.TextureCoords.Add(Point2((float)pointIndex * textureStep, 1.0f));
            mesh.Faces.Add(Face(vertexIndex, vertexIndex + 2, vertexIndex + 1));
            mesh.Faces.Add(Face(vertexIndex + 1, vertexIndex + 2, vertexIndex + 3));
        }

        mesh.VertexCoords.Add(edge.Points[0]);
        mesh.VertexCoords.Add(nextEdge.Points[0]);
        mesh.NormalCoords.Add(normal.Points[0]);
        mesh.NormalCoords.Add(nextNormal.Points[0]);
        mesh.TextureCoords.Add(Point2(1.0f, 0.0f));
        mesh.TextureCoords.Add(Point2(1.0f, 1.0f));
    }
}

TrackMesh* TrackMeshResolvingFactory::Make(Resolver&)
{
    return new TrackMesh();
}
