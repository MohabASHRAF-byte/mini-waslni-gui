
#ifndef ALGORITHM_H
#define ALGORITHM_H
#pragma once
#include<bits/stdc++.h>
#include "Point.h"
#include "NodeConverter.h"
#include <QVector>
#define ll long long
using namespace std;
class Algorithm{
protected:
    Point src,destination;

public:
    static long long dst(Point p1, Point p2) {
        return sqrtl((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    }
    virtual void run(map<int,set<int>>&convertedGraph) = 0;
    virtual QVector<Point> getPath(map<int,set<int>>&convertedGraph) = 0;
};
#endif // ALGORITHM_H
