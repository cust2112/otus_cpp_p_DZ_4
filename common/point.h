#ifndef POINT_H
#define POINT_H


struct Point
{
    Point (int x = 0, int y = 0) : x (x), y (y) {}

    int sqDist2 (const Point &that);

    int x, y;
};


#endif // POINT_H
