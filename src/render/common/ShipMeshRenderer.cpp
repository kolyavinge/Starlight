#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <model/ShipMeasure.h>
#include <anx/GraphicResources.h>
#include <render/common/RenderConstants.h>
#include <render/common/ShipMeshRenderer.h>

ShipMeshRenderer::ShipMeshRenderer(Camera& camera) :
    _camera(camera)
{
    _shipMesh.Load(GraphicResources::GetShipMeshFilePath());
    _shipMesh.SwapYZ();
    _shipMesh.MoveToOrigin();
    _shipMesh.MoveToCenter((int)Mesh::Axis::X);
    Mesh::Size meshSize;
    _shipMesh.GetSize(meshSize);
    _shipMesh.SetScale(
        ShipMeasure::XLength / meshSize.XLength,
        ShipMeasure::YLength / meshSize.YLength,
        ShipMeasure::ZLength / meshSize.ZLength);
    _vboMeshRenderer.Init(_shipMesh);
    _vboMeshRenderer.LightPosition = RenderConstants::LightPosition;
}

void ShipMeshRenderer::Render(Ship& ship, int textureIndex)
{
    _vboMeshRenderer.SetActiveTextureIndex(textureIndex);
    _vboMeshRenderer.CameraPosition = _camera.Position;

    float radians;
    Vector3 pivot;
    ship.Border.GetAngleAndPivot(radians, pivot);

    glm::mat4 modelMatrix = glm::mat4(1.0f);
    modelMatrix = glm::translate(modelMatrix, glm::vec3(ship.Border.DownLeft.X, ship.Border.DownLeft.Y, ship.Border.DownLeft.Z));
    modelMatrix = glm::rotate(modelMatrix, radians, glm::vec3(pivot.X, pivot.Y, pivot.Z));
    modelMatrix = glm::translate(modelMatrix, glm::vec3(ShipMeasure::XLengthHalf, 0.0f, 0.0f));
    modelMatrix = glm::rotate(modelMatrix, ship.GetRollRadians(), glm::vec3(0.0f, 1.0f, 0.0f));

    _vboMeshRenderer.ModelMarix = glm::value_ptr(modelMatrix);

    _vboMeshRenderer.Render();
}

int ShipMeshRenderer::GetTexturesCount()
{
    return _shipMesh.Textures.GetCount();
}

ShipMeshRenderer* ShipMeshRendererResolvingFactory::Make(Resolver& resolver)
{
    return new ShipMeshRenderer(
        resolver.Resolve<Camera>());
}
