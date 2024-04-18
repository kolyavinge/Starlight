#pragma once

#include <lib/Object.h>
#include <lib/Array.h>
#include <calc/Vector3.h>
#include <model/TrackPointInfo.h>
#include <model/TrackEdge.h>

#define TrackMaxPoints 20000
#define TrackMaxMiddlePoints 10
#define TrackEdgesStep 10
#define TrackMaxEdges (TrackMaxPoints / TrackEdgesStep)

class TrackPoints : public Array<Vector3, TrackMaxPoints> { };

class TrackMiddlePoints : public Array<Array<Vector3, TrackMaxMiddlePoints>, TrackMaxPoints> { };

class TrackPointInfos : public Array<TrackPointInfo, TrackMaxPoints> { };

class TrackEdges : public Array<TrackEdge, TrackMaxEdges> { };

class Track : public Object
{
    Vector3 _startFinishLine;

public:
    int StartFinishLineIndex;
    int PointsCount;
    int EdgesCount;
    TrackPoints OutsidePoints;
    TrackPoints InsidePoints;
    TrackPoints OutsidePointsInverseZ;
    TrackPoints InsidePointsInverseZ;
    TrackMiddlePoints MiddlePoints;
    TrackPoints Normals;
    TrackPointInfos PointInfos;
    TrackEdges OutsideEdges;
    TrackEdges InsideEdges;
    TrackEdges EdgeNormals;

    Track();

    void Init();
    int GetTrackPointIndexFor(Vector3& point, int startIndex);
    bool IsShipMovingInStraightDirection(int trackPointIndexFront, int trackPointIndexRear);
    int GetNextTrackPointIndex(int currentIndex);
    int GetPrevTrackPointIndex(int currentIndex);

protected:
    virtual void InternalInit() = 0;

private:
    void CenterTrackPoints();
    void InitInverseZPoints();
    void InitMiddlePoints();
    void InitNormals();
    void InitEdges();
    void InitEdges(TrackEdges& edges, TrackPoints& trackPoints);
    void InitEdgeNormals();
    float GetMinSquaredLengthForTrackPoint(Vector3& point, int trackPointIndex);
};
