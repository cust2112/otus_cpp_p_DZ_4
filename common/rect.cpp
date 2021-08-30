
#include <algorithm>

#include "rect.h"


Rect::Rect (const Point &p1, const Point &p2)
    : lt (Point (std::min (p1.x, p2.x), std::min (p1.y, p2.y))),
      rb (Point (std::max (p1.x, p2.x), std::max (p1.y, p2.y))) {
}


Rect::operator bool () const
{
    return lt.x <= rb.x && lt.y <= rb.y;
}


Rect operator| (const Rect &r1, const Rect &r2)
{
    return Rect (Point (std::min (r1.lt.x, r2.lt.x), std::min (r1.lt.y, r2.lt.y)),
                 Point (std::max (r1.rb.x, r2.rb.x), std::max (r1.rb.y, r2.rb.y)));
}


Rect operator& (const Rect &r1, const Rect &r2)
{
    return Rect (Point (std::max (r1.lt.x, r2.lt.x), std::max (r1.lt.y, r2.lt.y)),
                 Point (std::min (r1.rb.x, r2.rb.x), std::min (r1.rb.y, r2.rb.y)));
}
