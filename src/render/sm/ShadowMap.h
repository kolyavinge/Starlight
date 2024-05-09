#pragma once

#include <lib/Object.h>

class ShadowMap : public Object
{
public:
    unsigned int TextureId;
    float* ShadowMatrix;

    ShadowMap();
};
