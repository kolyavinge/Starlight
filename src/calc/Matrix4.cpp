#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <calc/Matrix4.h>

Matrix4::Matrix4()
{
    SetIdentity();
}

void Matrix4::SetIdentity()
{
    _matrix = glm::mat4(1.0f);
}

void Matrix4::SetBias()
{
    _matrix = glm::mat4(
        glm::vec4(0.5f, 0.0f, 0.0f, 0.0f),
        glm::vec4(0.0f, 0.5f, 0.0f, 0.0f),
        glm::vec4(0.0f, 0.0f, 0.5f, 0.0f),
        glm::vec4(0.5f, 0.5f, 0.5f, 1.0f));
}

void Matrix4::Mul(Matrix4& m)
{
    _matrix *= m._matrix;
}

void Matrix4::Translate(float x, float y, float z)
{
    _matrix = glm::translate(_matrix, glm::vec3(x, y, z));
}

void Matrix4::Translate(Vector3& v)
{
    _matrix = glm::translate(_matrix, glm::vec3(v.X, v.Y, v.Z));
}

void Matrix4::Rotate(float radians, float pivotX, float pivotY, float pivotZ)
{
    _matrix = glm::rotate(_matrix, radians, glm::vec3(pivotX, pivotY, pivotZ));
}

void Matrix4::Rotate(float radians, Vector3& pivot)
{
    _matrix = glm::rotate(_matrix, radians, glm::vec3(pivot.X, pivot.Y, pivot.Z));
}

void Matrix4::Scale(float x, float y, float z)
{
    _matrix = glm::scale(_matrix, glm::vec3(x, y, z));
}

void Matrix4::Scale(Vector3& v)
{
    _matrix = glm::scale(_matrix, glm::vec3(v.X, v.Y, v.Z));
}

void Matrix4::LookAt(Vector3& eyePosition, Vector3& lookAt, Vector3& upDirection)
{
    _matrix = glm::lookAt(
        glm::vec3(eyePosition.X, eyePosition.Y, eyePosition.Z),
        glm::vec3(lookAt.X, lookAt.Y, lookAt.Z),
        glm::vec3(upDirection.X, upDirection.Y, upDirection.Z));
}

void Matrix4::Perspective(float viewAngleRadians, float sizeAspect, float zNear, float zFar)
{
    _matrix = glm::perspective(viewAngleRadians, sizeAspect, zNear, zFar);
}

float* Matrix4::GetPtr()
{
    return glm::value_ptr(_matrix);
}
