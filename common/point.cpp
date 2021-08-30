
#include "point.h"


int Point::sqDist2 (const Point &that)
{
    int dx = that.x - x;
    int dy = that.y - y;

    return dx * dx + dy * dy;
}
