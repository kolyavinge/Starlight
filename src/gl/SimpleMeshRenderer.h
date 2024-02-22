#pragma once

#include <lib/Object.h>
#include <gl/Mesh.h>

class SimpleMeshRenderer : public Object
{
    int _activeTextureIndex;

public:
    SimpleMeshRenderer();

    void Render(Mesh mesh);
    void SetActiveTextureIndex(int textureIndex);
};
