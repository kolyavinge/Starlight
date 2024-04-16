#pragma once

#include <lib/Object.h>
#include <lib/String.h>
#include <lib/List.h>
#include <lib/Point2.h>
#include <calc/Vector3.h>
#include <gl/Face.h>
#include <gl/Texture.h>

class Mesh : public Object
{
public:
    enum class Axis
    {
        X = 1,
        Y = 2,
        Z = 4
    };

    struct Size
    {
        float MinX = 0.0f;
        float MinY = 0.0f;
        float MinZ = 0.0f;
        float MaxX = 0.0f;
        float MaxY = 0.0f;
        float MaxZ = 0.0f;
        float XLength = 0.0f;
        float YLength = 0.0f;
        float ZLength = 0.0f;
    };

    List<Vector3> VertexCoords;
    List<Vector3> NormalCoords;
    List<Point2> TextureCoords;
    List<Face> Faces;
    List<Texture> Textures;

    Mesh();

    void Load(String filePath, unsigned int meshIndex = 0);
    void Clear();
    void MoveToOrigin();
    void MoveToCenter(int axis);
    void SwapYZ();
    void SetScale(float x, float y, float z);
    bool IsLoaded();
    void GetSize(Size& result);
};
