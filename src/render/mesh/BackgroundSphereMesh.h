#pragma once

#include <lib/Object.h>
#include <lib/di/ResolvingFactory.h>
#include <gl/Mesh.h>
#include <render/common/BackgroundSphere.h>

class BackgroundSphereMesh : public Object
{
    Mesh _mesh;

public:
    BackgroundSphereMesh();

    Mesh& GetMesh();

private:
    void MakeVertices();
    void MakeSphereSegment(BackgroundSphere& sphere, int level, int point, float textureWidthStep, float textureHeightStep);
    void LoadTextures();
};

class BackgroundSphereMeshResolvingFactory : public ResolvingFactory<BackgroundSphereMesh>
{
public:
    BackgroundSphereMesh* Make(Resolver& resolver);
};
