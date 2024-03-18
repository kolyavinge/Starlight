#include <calc/Vector3.h>
#include <core/PowerUpGenerator.h>

void PowerUpGenerator::Generate(Track& track, List<PowerUp>& powerUps)
{
    GeneratePowerUps(powerUps);
    UpdatePositions(track, powerUps);
}

void PowerUpGenerator::UpdatePositions(Track& track, IArray<PowerUp>& powerUps)
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
    int randomTrackPoint = _rand.GetIntFromZeroToN(10 * track.PointsCount);
    while (randomTrackPoint >= track.PointsCount) randomTrackPoint -= track.PointsCount;

    Vector3 trackLengthVector(track.OutsidePoints[randomTrackPoint]);
    trackLengthVector.Sub(track.InsidePoints[randomTrackPoint]);
    const float trackLength = trackLengthVector.GetLength();
    const float randomLength = _rand.GetFloatFromZeroToN(trackLength - 2.0f) + 1.0f;
    trackLengthVector.SetLength(randomLength);

    powerUp.Middle = track.InsidePoints[randomTrackPoint];
    powerUp.Middle.Add(trackLengthVector);

    trackLengthVector.SetLength(0.5f);
    powerUp.From = powerUp.Middle;
    powerUp.To = powerUp.Middle;
    powerUp.From.Sub(trackLengthVector);
    powerUp.To.Add(trackLengthVector);
}
