#pragma once

#include <lib/Object.h>
#include <calc/Matrix4.h>

class ShadowMap : public Object
{
public:
    unsigned int FBOId;
    unsigned int TextureId;
    Matrix4 ShadowMatrix;

    ShadowMap();

    ~ShadowMap();
};
