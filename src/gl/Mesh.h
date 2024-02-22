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
    List<Vector3> _vertexCoords;
    List<Vector3> _normalCoords;
    List<Point2> _textureCoords;
    List<Face> _faces;
    List<Texture> _textures;
    int _activeTextureIndex;

public:
    enum class LoadFlags
    {
        NoTexture = 1
    };

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

    Mesh();

    void Load(String filePath, unsigned int meshIndex = 0, unsigned int flags = 0);
    void SetActiveTextureIndex(int textureIndex);
    void Render();
    void MoveToOrigin();
    void MoveToCenter(int axis);
    void SwapYZ();
    bool IsLoaded();
    void GetSize(Size& result);
};
