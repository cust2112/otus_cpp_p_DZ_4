#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H


class Gui;


class GraphicsItem {
public:
    virtual ~GraphicsItem () {}

    virtual void draw (Gui &gui) = 0;
};


#endif // GRAPHICSITEM_H
