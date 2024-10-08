#include <lib/Numeric.h>
#include <model/ShipMeasure.h>
#include <model/Ship.h>

Ship::Ship() :
    Weapon(_weapon)
{
    InitForPlayer();
}

void Ship::InitForPlayer()
{
    _rollRadiansRate = 1.5f;
    State = ShipState::Active;
    Controls.Init();
    ThrottleTime = 0;
    TurnAngleRadians = 0;
    VelocityValue = 0;
    PrevVelocityValue = 0;
    CentralLine.Init();
    Border.Init();
    Weapon.Init();
    Nitros.Init();
    Health = 1.0f;
    IsDamaged = false;
    IsPowerUpPicked = false;
    DelayIterations = 0;
    VelocityFunction.Init();
    VelocityFunction.AddDelta(AIData.VelocityDelta);
    CompletedRaceDistance = 0;
    RacePosition = 0;
}

void Ship::InitForEnemy()
{
    InitForPlayer();
    _rollRadiansRate = 0.0f;
}

void Ship::OrientationByFrontPoint(Vector3& frontMiddlePoint, Vector3 direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = frontMiddlePoint;
    CentralLine.Rear = frontMiddlePoint;
    CentralLine.Rear.Sub(direction);
}

void Ship::OrientationByRearPoint(Vector3& rearMiddlePoint, Vector3 direction)
{
    direction.SetLength(ShipMeasure::YLength);
    CentralLine.Front = rearMiddlePoint;
    CentralLine.Rear = rearMiddlePoint;
    CentralLine.Front.Add(direction);
}

void Ship::SaveCurrentCentralLine()
{
    PrevCentralLine = CentralLine;
}

bool Ship::IsMoving()
{
    return !Numeric::FloatEquals(VelocityValue, 0.0f) || !Deviation.IsZero();
}

float Ship::GetRollRadians()
{
    return _rollRadiansRate * TurnAngleRadians;
}

Vector3 Ship::GetVelocityVector()
{
    Vector3 result;
    if (VelocityValue > 0.0f)
    {
        result.Set(CentralLine.Front);
        result.Sub(CentralLine.Rear);
        result.SetLength(VelocityValue);
    }

    return result;
}

void Ship::AddHealth(float value)
{
    Health += value;
    if (Health > 1.0f)
    {
        Health = 1.0f;
    }
}

void Ship::Damage(float damageValue)
{
    Health -= damageValue;
    if (Health < 0.0f)
    {
        Health = 0.0f;
    }
}

bool Ship::IsHealtFull()
{
    return Health == 1.0f;
}

void Ship::Explode()
{
    State = ShipState::Exploded;
    Controls.Init();
    DelayIterations = 120;
}

void Ship::Reset()
{
    State = ShipState::Reseted;
    Controls.Init();
    ThrottleTime = 0;
    TurnAngleRadians = 0;
    VelocityValue = 0;
    PrevVelocityValue = 0;
    Weapon.Init();
    Nitros.Init();
    Health = 1.0f;
    DelayIterations = 50;
}

bool Ship::CanControlled()
{
    return State == ShipState::Active || State == ShipState::Prepared;
}

void Ship::GetModelMatrix(Matrix4& modelMatrix)
{
    float radians;
    Vector3 pivot;
    Border.GetAngleAndPivot(radians, pivot);
    modelMatrix.Translate(Border.DownLeft);
    modelMatrix.Rotate(radians, pivot);
    modelMatrix.Translate(ShipMeasure::XLengthHalf, 0.0f, 0.0f);
    modelMatrix.Rotate(GetRollRadians(), 0.0f, 1.0f, 0.0f);
}
