#ifndef EDITOR_H
#define EDITOR_H

#include <list>
#include <memory>
#include <string>

#include "../common/rect.h"
#include "../serialize/simpleserializer/simpleserializerfactory.h"
#include "selectablegraphicsitem.h"


class Gui;


class Editor {
public:
    explicit Editor (Gui &gui, SerializerFactoryUPtr sf =
            SerializerFactoryUPtr (new SimpleSerializerFactory ()));

    const char *getCopyrightMsg ();

    void createDocument ();
    void loadDocument (const std::string &fileName);
    void saveDocument (const std::string &fileName);

    void addLine (const Point &p1);
    void addEllipse (const Point &p1);
    void setCurrentItemP2 (const Point &p2);
    void selectItemNearest2 (const Point &p);
    void deleteSelectedItem ();
    void unselectCurrentItem ();


private:
    typedef std::unique_ptr <SelectableGraphicsItem> Item;
    typedef std::list <Item> Items;

    Items items;
    Items::iterator currentItem;

    Gui &gui;
    SerializerFactoryUPtr sf;


    void addItem (SelectableGraphicsItem *item);
    void select (Items::iterator item);
    void ensureSelected ();
    void redraw (const Rect &invalidated);

    void ensureItemCreatorsRegistered ();
    std::string getDocumentHeader ();
    std::string getDocumentFooter ();
};


#endif // EDITOR_H
