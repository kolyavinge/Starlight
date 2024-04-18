#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <model/Track.h>
#include <gl/Mesh.h>

class TrackMesh : public Object
{
public:
    void MakeGroundMesh(Track& track, Mesh& mesh);
    void MakeEdgeMesh(Track& track, Mesh& mesh);

private:
    void MakeGroundSegment(Track& track, int startPointIndex, int endPointIndex, int segmentPointStep, int segmentsCount, float startTextureY, Mesh& mesh);
    void MakeEdgeMesh(int edgesCount, TrackEdges& edges, TrackEdges& normals, Mesh& mesh);
};

class TrackMeshResolvingFactory : public ResolvingFactory<TrackMesh>
{
public:
    TrackMesh* Make(Resolver& resolver);
};
