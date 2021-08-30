#ifndef TEXTMODECANVAS_H
#define TEXTMODECANVAS_H

#include <ostream>
#include <string>
#include <vector>

#include "../../common/rect.h"


class TextModeCanvas {
public:
    TextModeCanvas (int width, int height);

    Rect getBoundingBox () const;
    void putPixel (const Point &p, char c);
    void clear (const Rect &r);


private:
    typedef std::vector <std::string> Lines;

    int width, height;
    Lines lines;


    friend std::ostream &operator<< (std::ostream &os, const TextModeCanvas &cnv);
};


std::ostream &operator<< (std::ostream &os, const TextModeCanvas &cnv);


#endif // TEXTMODECANVAS_H
