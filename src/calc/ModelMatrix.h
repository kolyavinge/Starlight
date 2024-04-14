#pragma once

#include <glm/ext/matrix_float4x4.hpp>
#include <lib/Object.h>
#include <calc/Vector3.h>

class ModelMatrix : public Object
{
    glm::mat4 _matrix;

public:
    ModelMatrix();

    void SetIdentity();
    void Translate(float x, float y, float z);
    void Translate(Vector3& v);
    void Rotate(float radians, float pivotX, float pivotY, float pivotZ);
    void Rotate(float radians, Vector3& pivot);
    void Scale(float x, float y, float z);
    void Scale(Vector3& v);
    float* GetPtr();
};
