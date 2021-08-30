#ifndef RECT_H
#define RECT_H

#include "point.h"


struct Rect
{
    Rect (const Point &p1, const Point &p2);

    operator bool () const;


    Point lt, rb;
};


Rect operator| (const Rect &r1, const Rect &r2);
Rect operator& (const Rect &r1, const Rect &r2);


#endif // RECT_H
