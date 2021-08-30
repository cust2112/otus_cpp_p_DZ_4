
#include <sstream>

#include "../common/utils.h"
#include "line.h"


const std::string Line::TITLE = "Линия";


Serializable *Line::fromContents (const std::string &contents)
{
    Strings argList = splitArgs (contents, 4);


    Point p1 (str2int (argList[0]), str2int (argList[1]));
    Point p2 (str2int (argList[2]), str2int (argList[3]));

    Line *l = new Line (p1);

    l->setP2 (p2);


    return l;
}


Line::~Line () {
}


void Line::setP2 (const Point &p2)
{
    this->p2 = p2;
}


Rect Line::getBoundingBox () const
{
    return Rect (p1, p2);
}


void Line::draw (Gui &gui, Gui::DrawStyle style)
{
    gui.drawLine (p1, p2, style);
}


const std::string &Line::getTitle () const
{
    return TITLE;
}


std::string Line::getContents () const
{
    std::stringstream ss;

    ss << p1.x << ' ' << p1.y << ' ' << p2.x << ' ' << p2.y;

    return ss.str ();
}


Point Line::getCenter () const
{
    return Point ((p1.x + p2.x) / 2, (p1.y + p2.y) / 2);
}
