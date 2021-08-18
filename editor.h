#ifndef EDITOR_H
#define EDITOR_H

#include <string>


class GraphicsItem;
class Gui;


class Editor {
public:
    Editor (Gui &gui);

    void createDocument ();
    void loadDocument (const std::string &fileName);
    void saveDocument (const std::string &fileName);

    void addLine (int left, int top);
    void addEllipse (int left, int top);

    GraphicsItem *findGraphicsItem (int x, int y, int maxDist);
    void removeGraphicsItem (GraphicsItem *item);
};


#endif // EDITOR_H
