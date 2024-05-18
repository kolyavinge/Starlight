#pragma once

#include <glm/ext/matrix_float4x4.hpp>
#include <lib/Object.h>
#include <calc/Vector3.h>

class Matrix4 : public Object
{
    glm::mat4 _matrix;

public:
    Matrix4();

    void SetIdentity();
    void SetBias();
    void Mul(Matrix4& m);
    Vector3 Mul(Vector3& v);
    void Translate(float x, float y, float z);
    void Translate(Vector3& v);
    void Rotate(float radians, float pivotX, float pivotY, float pivotZ);
    void Rotate(float radians, Vector3& pivot);
    void Scale(float x, float y, float z);
    void Scale(Vector3& v);
    void LookAt(Vector3& eyePosition, Vector3& lookAt, Vector3& upDirection);
    void Perspective(float viewAngleRadians, float sizeAspect, float zNear, float zFar);
    float* GetPtr();
};
