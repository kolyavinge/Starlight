#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <calc/ModelMatrix.h>

ModelMatrix::ModelMatrix()
{
    SetIdentity();
}

void ModelMatrix::SetIdentity()
{
    _matrix = glm::mat4(1.0f);
}

void ModelMatrix::Translate(float x, float y, float z)
{
    _matrix = glm::translate(_matrix, glm::vec3(x, y, z));
}

void ModelMatrix::Translate(Vector3& v)
{
    _matrix = glm::translate(_matrix, glm::vec3(v.X, v.Y, v.Z));
}

void ModelMatrix::Rotate(float radians, float pivotX, float pivotY, float pivotZ)
{
    _matrix = glm::rotate(_matrix, radians, glm::vec3(pivotX, pivotY, pivotZ));
}

void ModelMatrix::Rotate(float radians, Vector3& pivot)
{
    _matrix = glm::rotate(_matrix, radians, glm::vec3(pivot.X, pivot.Y, pivot.Z));
}

void ModelMatrix::Scale(float x, float y, float z)
{
    _matrix = glm::scale(_matrix, glm::vec3(x, y, z));
}

void ModelMatrix::Scale(Vector3& v)
{
    _matrix = glm::scale(_matrix, glm::vec3(v.X, v.Y, v.Z));
}

float* ModelMatrix::GetPtr()
{
    return glm::value_ptr(_matrix);
}
