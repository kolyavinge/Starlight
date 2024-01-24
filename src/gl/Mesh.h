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
    void MoveToOrigin();
    void CalculateXYZLength();
    bool IsLoaded();
};
