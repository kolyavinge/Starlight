#include <calc/Vector3.h>
#include <core/PowerUpGenerator.h>

void PowerUpGenerator::Generate(Track& track, List<PowerUp>& powerUps)
{
    GeneratePowerUps(powerUps);
    UpdatePositions(track, powerUps);
}

void PowerUpGenerator::UpdatePositions(Track& track, List<PowerUp>& powerUps)
{
    for (int i = 0; i < powerUps.GetCount(); i++)
    {
        PowerUp& p = powerUps[i];
        if (!p.IsActive)
        {
            GenerateNewPosition(track, p);
            p.IsActive = true;
        }
    }
}

void PowerUpGenerator::GeneratePowerUps(List<PowerUp>& powerUps)
{
    powerUps.Clear();
    // health
    for (int i = 0; i < 2; i++)
    {
        PowerUp p;
        GenerateHealthPowerUp(p);
        powerUps.Add(p);
    }
    // machinegun
    for (int i = 0; i < 4; i++)
    {
        PowerUp p;
        GenerateMachinegunPowerUp(p);
        powerUps.Add(p);
    }
}

void PowerUpGenerator::GenerateHealthPowerUp(PowerUp& powerUp)
{
    powerUp.IsActive = false;
    powerUp.Kind = PowerUpKind::Health;
    powerUp.Value = 0.25f;
}

void PowerUpGenerator::GenerateMachinegunPowerUp(PowerUp& powerUp)
{
    powerUp.IsActive = false;
    powerUp.Kind = PowerUpKind::Machinegun;
    powerUp.Value = 50.0f;
}

void PowerUpGenerator::GenerateNewPosition(Track& track, PowerUp& powerUp)
{
    const int trackPoint = _rand.GetIntFromZeroToN(track.PointsCount);
    Vector3 trackLengthVector(track.OutsidePoints[trackPoint]);
    trackLengthVector.Sub(track.InsidePoints[trackPoint]);
    const float trackLength = trackLengthVector.GetLength();
    const float generatedLength = _rand.GetFloatFromZeroToN(trackLength - 2.0f) + 1.0f;
    trackLengthVector.SetLength(generatedLength);
    powerUp.Position = track.InsidePoints[trackPoint];
    powerUp.Position.Add(trackLengthVector);
}
