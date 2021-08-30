#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include "../common/rect.h"
#include "../gui/gui.h"


class GraphicsItem {
public:
    virtual ~GraphicsItem () {}

    virtual void setP2 (const Point &p2) = 0;
    virtual Rect getBoundingBox () const = 0;

    virtual void draw (Gui &gui, Gui::DrawStyle style = Gui::NORMAL) = 0;
};


#endif // GRAPHICSITEM_H
