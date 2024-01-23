#pragma once

#include <assimp/scene.h>
#include <lib/Object.h>
#include <lib/Exceptions.h>
#include <lib/String.h>
#include <lib/List.h>
#include <lib/Point2.h>
#include <calc/Vector3.h>
#include <gl/Texture.h>

class LoadMeshException : public Exception {};

class Mesh : public Object
{
    struct Face
    {
        unsigned int i0 = 0;
        unsigned int i1 = 0;
        unsigned int i2 = 0;
    };

    List<Vector3> _vertexCoords;
    List<Vector3> _normalCoords;
    List<Point2> _textureCoords;
    List<Face> _faces;
    Texture _texture;
    float _xLength;
    float _yLength;
    float _zLength;

public:
    enum Axis
    {
        X = 1,
        Y = 2,
        Z = 4
    };

    Mesh();

    void Load(String filePath, unsigned int meshIndex = 0);
    void Render();
    float GetXLength();
    float GetYLength();
    float GetZLength();
    void MoveToCenter(int axis);
    void SwapYZ();

private:
    void InitMesh(aiMesh* aiMesh);
    void InitMaterials(const aiScene* aiScene, String filePath);
    void MoveToOrigin();
    void CalculateXYZLength();
    bool IsAlreadyLoaded();
};
