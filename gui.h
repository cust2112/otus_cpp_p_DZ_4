#ifndef GUI_H
#define GUI_H


class Editor;


class Gui {
public:
    Gui ();

    void setEditor (Editor *editor);

    void startEventLoop () {}

    void drawLine (int left, int top, int right, int bottom);
    void drawEllipse (int left, int top, int right, int bottom);
};


#endif // GUI_H
