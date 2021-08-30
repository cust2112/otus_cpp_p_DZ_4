#ifndef GUI_H
#define GUI_H

#include "../common/rect.h"


class Editor;


class Gui {
public:
    Gui ();
    virtual ~Gui ();


    void setEditor (Editor *editor);

    virtual void startEventLoop () = 0;


    enum DrawStyle {NORMAL, HIGHLIGHTED};

    virtual void beginPaint (const Rect &invalidated) = 0;
    virtual void drawLine (const Point &p1, const Point &p2,
                           Gui::DrawStyle style = Gui::NORMAL) = 0;
    virtual void drawEllipse (const Point &center, int a, int b,
                              Gui::DrawStyle style = Gui::NORMAL) = 0;
    virtual void endPaint () = 0;

    virtual Rect getViewPort () = 0;

    void setDisplayable (bool b) { displayable = b; }


protected:
    bool getDisplayable () const { return displayable; }
    Editor *getEditor ();


private:
    bool displayable;
    Editor *editor;
};


#endif // GUI_H
