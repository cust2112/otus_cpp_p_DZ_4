
#include <stdexcept>

#include "textmodecanvas.h"


TextModeCanvas::TextModeCanvas (int width, int height)
    : width (width), height (height)
{
    if (width <= 0 || height <= 0)
        throw std::runtime_error ("TextModeCanvas: incorrect argument");


    lines.reserve (height);

    for (int i = 0; i < height; ++i)
        lines.emplace_back (width, ' ');
}


Rect TextModeCanvas::getBoundingBox () const
{
    return Rect (Point (0, 0), Point (width - 1, height - 1));
}


void TextModeCanvas::putPixel (const Point &p, char c)
{
    if (p.x < 0 || p.x >= width || p.y < 0 || p.y >= height)
        return;


    lines[p.y][p.x] = c;
}


void TextModeCanvas::clear (const Rect &r)
{
    Rect r1 = r & getBoundingBox ();


    for (int i = r1.lt.y; i <= r1.rb.y; ++i) {

        std::string &line = lines[i];

        for (int j = r1.lt.x; j <= r1.rb.x; ++j)
            line[j] = ' ';
    }
}


std::ostream &operator<< (std::ostream &os, const TextModeCanvas &cnv)
{
    for (int i = 0; i < cnv.height; ++i)
        os << cnv.lines[i] << std::endl;

    return os;
}
