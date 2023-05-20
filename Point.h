
#ifndef POINT_H
#define POINT_H
#pragma once
#define oo INT32_MAX
const int limitY = 36434;

class Point{
public:
    int x,y;
    bool compare(Point &tmp) {
        return (tmp.x == this->x && tmp.y == this->y);
    }
};
#endif // POINT_H
