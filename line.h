#ifndef LINE_H
#define LINE_H

#include "graphicsitem.h"


class Editor;


class Line : public GraphicsItem {
public:
    virtual ~Line ();

    virtual void draw (Gui &gui);


private:
    friend class Editor;
    Line (int left, int top);
};


#endif // LINE_H
