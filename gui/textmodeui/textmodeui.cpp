
#include <cmath>
#include <iostream>

#include "../../common/utils.h"
#include "../../editor/editor.h"
#include "textmodeui.h"


TextModeUI::TextModeUI ()
    : cnv (79, 24)
{
    cmdHandlers.insert (CmdHandlers::value_type ("al", &TextModeUI::addLine));
    cmdHandlers.insert (CmdHandlers::value_type ("ae", &TextModeUI::addEllipse));
    cmdHandlers.insert (CmdHandlers::value_type ("cur", &TextModeUI::selectItemNearest2));
    cmdHandlers.insert (CmdHandlers::value_type ("del", &TextModeUI::deleteSelectedItem));
    cmdHandlers.insert (CmdHandlers::value_type ("s", &TextModeUI::saveDocument));
    cmdHandlers.insert (CmdHandlers::value_type ("l", &TextModeUI::loadDocument));
    cmdHandlers.insert (CmdHandlers::value_type ("r", &TextModeUI::refreshDisplay));
    cmdHandlers.insert (CmdHandlers::value_type ("h", &TextModeUI::printHelpMsg));
}


TextModeUI::~TextModeUI () {
}


void TextModeUI::startEventLoop ()
{
    printHelpMsg ();


    for (std::string cmd = getline (); cmd != "q"; cmd = getline ())
        processCommand (cmd);

    setEditor (nullptr);


    std::cout << "Bye!\n";
}


void TextModeUI::beginPaint (const Rect &invalidated)
{
    cnv.clear (invalidated);
}


void TextModeUI::drawLine (const Point &p1, const Point &p2, DrawStyle style)
{
    char c = style == HIGHLIGHTED ? '*' : '.';

    int absXDiff = abs (p1.x - p2.x);
    int absYDiff = abs (p1.y - p2.y);


    if (absXDiff >= absYDiff) {

        int dx = p1.x <= p2.x ? 1 : -1;
        int dy = p1.y <= p2.y ? 1 : -1;
        int halfAbsXDiff = (absXDiff + 1) / 2;
        Point p = p1;

        for (int &x = p.x, &y = p.y, yTrigger = 0; x != p2.x; x += dx) {

            cnv.putPixel (p, c);

            yTrigger += absYDiff;

            if (yTrigger >= halfAbsXDiff)
                yTrigger -= absXDiff, y += dy;
        }

        cnv.putPixel (p2, c);

    } else {

        int dx = p1.x <= p2.x ? 1 : -1;
        int dy = p1.y <= p2.y ? 1 : -1;
        int halfAbsYDiff = (absYDiff + 1) / 2;
        Point p = p1;

        for (int &x = p.x, &y = p.y, xTrigger = 0; y != p2.y; y += dy) {

            cnv.putPixel (p, c);

            xTrigger += absXDiff;

            if (xTrigger >= halfAbsYDiff)
                xTrigger -= absYDiff, x += dx;
        }

        cnv.putPixel (p2, c);
    }
}


void TextModeUI::drawEllipse (const Point &center, int a, int b, DrawStyle style)
{
    char c = style == HIGHLIGHTED ? '*' : '.';

    if (a == 0 && b == 0) {
        cnv.putPixel (center, c);
        return;
    }


    a = abs (a);
    b = abs (b);


    if (a >= b) {

        float rcpSqA = 1.f / (a * a);
        Point p;

        for (int dx = 0; dx <= a; ++dx) {

            int dy = round (b * sqrt (1 - dx * dx * rcpSqA));

            p.x = center.x - dx;  p.y = center.y - dy;  cnv.putPixel (p, c);
            /*p.x = center.x - dx;*/  p.y = center.y + dy;  cnv.putPixel (p, c);
            p.x = center.x + dx;  p.y = center.y - dy;  cnv.putPixel (p, c);
            /*p.x = center.x + dx;*/  p.y = center.y + dy;  cnv.putPixel (p, c);
        }

    } else {

        float rcpSqB = 1.f / (b * b);
        Point p;

        for (int dy = 0; dy <= b; ++dy) {

            int dx = round (a * sqrt (1 - dy * dy * rcpSqB));

            p.x = center.x - dx;  p.y = center.y - dy;  cnv.putPixel (p, c);
            /*p.x = center.x - dx;*/  p.y = center.y + dy;  cnv.putPixel (p, c);
            p.x = center.x + dx;  p.y = center.y - dy;  cnv.putPixel (p, c);
            /*p.x = center.x + dx;*/  p.y = center.y + dy;  cnv.putPixel (p, c);
        }
    }
}


void TextModeUI::endPaint ()
{
    std::cout << cnv;
}


Rect TextModeUI::getViewPort ()
{
    return cnv.getBoundingBox ();
}


void TextModeUI::addLine (const std::string &args)
{
    Strings argList = splitArgs (args, 4);


    Point p1 (str2int (argList[0]), str2int (argList[1]));
    Point p2 (str2int (argList[2]), str2int (argList[3]));

    getEditor ()->addLine (p1);
    getEditor ()->setCurrentItemP2 (p2);
}


void TextModeUI::addEllipse (const std::string &args)
{
    Strings argList = splitArgs (args, 4);


    Point p1 (str2int (argList[0]), str2int (argList[1]));
    Point p2 (p1.x + str2int (argList[2]), p1.y + str2int (argList[3]));

    getEditor ()->addEllipse (p1);
    getEditor ()->setCurrentItemP2 (p2);
}


void TextModeUI::selectItemNearest2 (const std::string &args)
{
    Strings argList = splitArgs (args, 2);


    Point p1 (str2int (argList[0]), str2int (argList[1]));

    getEditor ()->selectItemNearest2 (p1);
}


void TextModeUI::deleteSelectedItem (const std::string &args)
{
    Strings argList = splitArgs (args, 0);  UNUSED (argList);

    getEditor ()->deleteSelectedItem ();
}


void TextModeUI::loadDocument (const std::string &args)
{
    Strings argList = splitArgs (args, 1);

    getEditor ()->loadDocument (argList[0]);
}


void TextModeUI::saveDocument (const std::string &args)
{
    Strings argList = splitArgs (args, 1);

    getEditor ()->saveDocument (argList[0]);
}


void TextModeUI::refreshDisplay (const std::string &args)
{
    Strings argList = splitArgs (args, 0);  UNUSED (argList);

    endPaint ();
}


void TextModeUI::printHelpMsg (const std::string &args)
{
    Strings argList = splitArgs (args, 0);  UNUSED (argList);


    std::cout << getEditor ()->getCopyrightMsg () << std::endl;
    std::cout << "(Text Mode UI 79x24)\n\n";
    std::cout << "Commands:\n"
                "\tal <x1> <y1> <x2> <y2> - add line\n"
                "\tae <xc> <yc> <a> <b> - add ellipse\n"
                "\tcur <x> <y> - select graphics item, nearest to (x, y)\n"
                "\tdel - delete selected graphics item\n"
                "\ts <filename>[.ged] - save scene info to a file\n"
                "\tl <filename>[.ged] - load scene info from a file\n"
                "\tr - refresh display\n"
                "\th - print this help message\n"
                "\tq - quit\n";
}


std::string TextModeUI::getline ()
{
    std::string cmd;

    std::cout << "(:" << std::flush;

    std::getline (std::cin, cmd);


    return cmd;
}


void TextModeUI::splitIntoKeywordAndArgs (const std::string &cmd,
                                           std::string &keyword, std::string &args)
{
    size_t spacePos = cmd.find (' ');

    keyword = std::string (cmd, 0, spacePos);
    args = spacePos < cmd.size () ? std::string (cmd, spacePos + 1) :
                                    std::string ();
}


void TextModeUI::processCommand (const std::string &cmd)
{
    std::string keyword, args;

    splitIntoKeywordAndArgs (cmd, keyword, args);

    if (keyword.empty ())
        return;


    auto i = cmdHandlers.find (keyword);

    if (i == cmdHandlers.end ())
        std::cout << "Command '" << keyword << "' not known\n";
    else
        try {
            (this->*i->second) (args);
        } catch (std::exception &e) {
            std::cout << "Error: " << e.what () << std::endl;
        }
}
