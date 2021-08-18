#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "graphicsitem.h"


class Editor;


class Ellipse : public GraphicsItem {
public:
    virtual ~Ellipse ();

    virtual void draw (Gui &gui);


private:
    friend class Editor;
    Ellipse (int left, int top);
};


#endif // ELLIPSE_H
