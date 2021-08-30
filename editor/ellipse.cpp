
#include <sstream>

#include "../common/utils.h"
#include "ellipse.h"


const std::string Ellipse::TITLE = "Эллипс";


Serializable *Ellipse::fromContents (const std::string &contents)
{
    Strings argList = splitArgs (contents, 4);


    Point p1 (str2int (argList[0]), str2int (argList[1]));
    Point p2 (p1.x + str2int (argList[2]), p1.y + str2int (argList[3]));

    Ellipse *e = new Ellipse (p1);

    e->setP2 (p2);


    return e;
}


Ellipse::~Ellipse () {
}


void Ellipse::setP2 (const Point &p2)
{
    a = abs (center.x - p2.x);
    b = abs (center.y - p2.y);
}


Rect Ellipse::getBoundingBox () const
{
    return Rect (Point (center.x - a, center.y - b),
                 Point (center.x + a, center.y + b));
}


void Ellipse::draw (Gui &gui, Gui::DrawStyle style)
{
    gui.drawEllipse (center, a, b, style);
}


const std::string &Ellipse::getTitle () const
{
    return TITLE;
}


std::string Ellipse::getContents () const
{
    std::stringstream ss;

    ss << center.x << ' ' << center.y << ' ' << a << ' ' << b;

    return ss.str ();
}


Point Ellipse::getCenter () const
{
    return center;
}
