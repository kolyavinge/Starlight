#include <lib/Exceptions.h>
#include <calc/VectorCalculator.h>
#include <calc/Geometry.h>
#include <model/Track.h>

Track::Track()
{
    StartFinishLineIndex = 0;
    PointsCount = 0;
    EdgesCount = 0;
}

void Track::Init()
{
    InternalInit();
    CenterTrackPoints();

    InsidePoints[PointsCount] = InsidePoints[0];
    OutsidePoints[PointsCount] = OutsidePoints[0];

    InitInverseZPoints();
    OutsidePointsInverseZ[PointsCount] = OutsidePointsInverseZ[0];
    InsidePointsInverseZ[PointsCount] = InsidePointsInverseZ[0];

    InitMiddlePoints();

    InitNormals();
    Normals[PointsCount] = Normals[0];

    InitEdges();
    InsideEdges[EdgesCount] = InsideEdges[0];
    OutsideEdges[EdgesCount] = OutsideEdges[0];

    InitEdgeNormals();
    EdgeNormals[EdgesCount] = EdgeNormals[0];

    _startFinishLine.Set(OutsidePoints[StartFinishLineIndex]);
    _startFinishLine.Sub(InsidePoints[StartFinishLineIndex]);
}

int Track::GetTrackPointIndexFor(Vector3& point, int startIndex)
{
    int result = startIndex;
    float minLength = GetMinSquaredLengthForTrackPoint(point, startIndex);
    for (int i = GetNextTrackPointIndex(startIndex); true; i = GetNextTrackPointIndex(i))
    {
        float length = GetMinSquaredLengthForTrackPoint(point, i);
        if (length < minLength)
        {
            minLength = length;
            result = i;
        }
        else
        {
            break;
        }
    }
    for (int i = GetPrevTrackPointIndex(startIndex); true; i = GetPrevTrackPointIndex(i))
    {
        float length = GetMinSquaredLengthForTrackPoint(point, i);
        if (length < minLength)
        {
            minLength = length;
            result = i;
        }
        else
        {
            break;
        }
    }

    return result;
}

bool Track::IsShipMovingInStraightDirection(int trackPointIndexFront, int trackPointIndexRear)
{
    if (trackPointIndexFront == trackPointIndexRear) throw ArgumentException();

    Vector3 base(InsidePoints[trackPointIndexFront]);
    base.Sub(OutsidePoints[trackPointIndexFront]);

    Vector3 straightDirection(InsidePoints[trackPointIndexFront]);
    straightDirection.Sub(InsidePoints[GetPrevTrackPointIndex(trackPointIndexFront)]);

    Vector3 shipDirection(InsidePoints[trackPointIndexFront]);
    shipDirection.Sub(InsidePoints[trackPointIndexRear]);

    return VectorCalculator::IsSameDirection(base, shipDirection, straightDirection);
}

int Track::GetNextTrackPointIndex(int currentIndex)
{
    currentIndex++;
    if (currentIndex == PointsCount) currentIndex = 0;

    return currentIndex;
}

int Track::GetPrevTrackPointIndex(int currentIndex)
{
    currentIndex--;
    if (currentIndex == -1) currentIndex = PointsCount - 1;

    return currentIndex;
}

void Track::CenterTrackPoints()
{
    float minX = InsidePoints[0].X;
    float maxX = InsidePoints[0].X;
    float minY = InsidePoints[0].Y;
    float maxY = InsidePoints[0].Y;
    for (int i = 1; i < PointsCount; i++)
    {
        if (InsidePoints[i].X < minX) minX = InsidePoints[i].X;
        if (InsidePoints[i].X > maxX) maxX = InsidePoints[i].X;
        if (InsidePoints[i].Y < minY) minY = InsidePoints[i].Y;
        if (InsidePoints[i].Y > maxY) maxY = InsidePoints[i].Y;
    }

    float widthHalf = (maxX - minX) / 2.0f;
    float heightHalf = (maxY - minY) / 2.0f;
    float deltaX = minX + widthHalf;
    float deltaY = minY + heightHalf;

    for (int i = 0; i < PointsCount; i++)
    {
        InsidePoints[i].X -= deltaX;
        OutsidePoints[i].X -= deltaX;
        InsidePoints[i].Y -= deltaY;
        OutsidePoints[i].Y -= deltaY;
    }
}

void Track::InitInverseZPoints()
{
    OutsidePointsInverseZ = OutsidePoints;
    InsidePointsInverseZ = InsidePoints;
    for (int i = 0; i < PointsCount; i++)
    {
        OutsidePointsInverseZ[i].Z *= -1.0f;
        InsidePointsInverseZ[i].Z *= -1.0f;
    }
}

void Track::InitMiddlePoints()
{
    for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
    {
        Vector3 v(OutsidePoints[pointIndex]);
        v.Sub(InsidePoints[pointIndex]);
        v.Div((float)TrackMaxMiddlePoints + 1.0f);

        MiddlePoints[pointIndex][0] = InsidePoints[pointIndex];
        MiddlePoints[pointIndex][0].Add(v);

        for (int i = 1; i < TrackMaxMiddlePoints; i++)
        {
            MiddlePoints[pointIndex][i] = MiddlePoints[pointIndex][i - 1];
            MiddlePoints[pointIndex][i].Add(v);
        }
    }
}

void Track::InitNormals()
{
    for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
    {
        VectorCalculator::GetNormalVector(
            InsidePoints[pointIndex],
            OutsidePoints[pointIndex],
            InsidePoints[pointIndex + 1],
            Normals[pointIndex]);
    }

    if (OutsidePoints[0].X < InsidePoints[0].X)
    {
        for (int pointIndex = 0; pointIndex < PointsCount; pointIndex++)
        {
            Normals[pointIndex].Mul(-1.0f);
        }
    }
}

void Track::InitEdges()
{
    EdgesCount = PointsCount / TrackEdgesStep;
    InitEdges(OutsideEdges, OutsidePoints);
    InitEdges(InsideEdges, InsidePoints);
}

void Track::InitEdges(TrackEdges& edges, TrackPoints& trackPoints)
{
    for (int edgeIndex = 0; edgeIndex < EdgesCount; edgeIndex++)
    {
        int trackPointIndex = TrackEdgesStep * edgeIndex;

        Vector3 pivotAxis(trackPoints[trackPointIndex + TrackEdgesStep]);
        pivotAxis.Sub(trackPoints[trackPointIndex]);
        pivotAxis.Normalize();

        Vector3 point = Normals[trackPointIndex];
        point.Mul(-1.0f);
        point.SetLength(0.5f);
        point.Add(trackPoints[trackPointIndex]);

        TrackEdge& edge = edges[edgeIndex];
        edge.Points[0].Set(point);

        float radians = TrackEdge::RadiansStep;
        for (int pointIndex = 1; pointIndex < edge.Points.GetCount(); pointIndex++)
        {
            Vector3 rotatedPoint = Geometry::RotatePoint3d(point, pivotAxis, trackPoints[trackPointIndex], radians);
            edge.Points[pointIndex].Set(rotatedPoint);
            radians += TrackEdge::RadiansStep;
        }
    }
}

void Track::InitEdgeNormals()
{
    for (int edgeIndex = 0; edgeIndex < EdgesCount; edgeIndex++)
    {
        for (int pointIndex = 0; pointIndex < TrackEdgeMaxPoints - 1; pointIndex++)
        {
            VectorCalculator::GetNormalVector(
                InsideEdges[edgeIndex].Points[pointIndex],
                InsideEdges[edgeIndex].Points[pointIndex + 1],
                InsideEdges[edgeIndex + 1].Points[pointIndex],
                EdgeNormals[edgeIndex].Points[pointIndex]);
        }

        VectorCalculator::GetNormalVector(
            InsideEdges[edgeIndex].Points[TrackEdgeMaxPoints - 1],
            InsideEdges[edgeIndex].Points[0],
            InsideEdges[edgeIndex + 1].Points[TrackEdgeMaxPoints - 1],
            EdgeNormals[edgeIndex].Points[TrackEdgeMaxPoints - 1]);
    }
}

float Track::GetMinSquaredLengthForTrackPoint(Vector3& point, int trackPointIndex)
{
    Array<Vector3, TrackMaxMiddlePoints>& middlePoints = MiddlePoints[trackPointIndex];
    Vector3 v(middlePoints[0]);
    v.Sub(point);
    float minLengthSquared = v.GetLengthSquared();
    for (int i = 1; i < TrackMaxMiddlePoints; i++)
    {
        v = middlePoints[i];
        v.Sub(point);
        float length = v.GetLengthSquared();
        if (length < minLengthSquared)
        {
            minLengthSquared = length;
        }
    }

    return minLengthSquared;
}
