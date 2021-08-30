
#include <algorithm>
#include <cassert>

#include "../gui/gui.h"
#include "../serialize/simpleserializer/simpledocumentwriter.h"
#include "editor.h"
#include "ellipse.h"
#include "line.h"


Editor::Editor (Gui &gui, SerializerFactoryUPtr sf)
    : currentItem (items.end ()), gui (gui), sf (std::move (sf))
{
    gui.setEditor (this);

    ensureItemCreatorsRegistered ();
}


const char *Editor::getCopyrightMsg ()
{
    return "Graphics editor demo. Copyright (c) 2021 Alex M. (Otus-cpp_p-2021-06)";
}


void Editor::loadDocument (const std::string &fileName)
{
    Items newItems;
    DocReaderUPtr r = sf.get ()->createDocumentReader (fileName);


    r.get ()->readDocumentHeader (getDocumentHeader ());

    for (Serializable *s = r.get ()->readItem ();
         s != nullptr; s = r.get ()->readItem ()) {

        SelectableGraphicsItem *i = dynamic_cast <SelectableGraphicsItem *> (s);

        assert (i);

        newItems.emplace_back (i);
    }

    r.get ()->readDocumentFooter (getDocumentFooter ());


    items.swap (newItems);

    redraw (gui.getViewPort ());
}


void Editor::saveDocument (const std::string &fileName)
{
    DocWriterUPtr w = sf.get ()->createDocumentWriter (fileName);


    w.get ()->writeDocumentHeader (getDocumentHeader ());

    for (Item &item : items)
        w.get ()->writeItem (item.get ()->getTitle (), item.get ()->getContents ());

    w.get ()->writeDocumentFooter (getDocumentFooter ());
}


void Editor::addLine (const Point &p1)
{
    addItem (new Line (p1));
}


void Editor::addEllipse (const Point &p1)
{
    addItem (new Ellipse (p1));
}


void Editor::setCurrentItemP2 (const Point &p2)
{
    ensureSelected ();


    Rect preOpBB = currentItem->get ()->getBoundingBox ();

    currentItem->get ()->setP2 (p2);

    Rect postOpBB = currentItem->get ()->getBoundingBox ();


    redraw (preOpBB | postOpBB);
}


void Editor::selectItemNearest2 (const Point &p)
{
    if (items.size () == 0)
        throw std::runtime_error ("no items");


    Items::iterator i = std::min_element (items.begin (), items.end (),
                                          [&p] (const Item &item1, const Item &item2)
    {
        return item1.get ()->getCenter ().sqDist2 (p) <
               item2.get ()->getCenter ().sqDist2 (p);
    });


    select (i);
}


void Editor::deleteSelectedItem ()
{
    ensureSelected ();


    Rect bb = currentItem->get ()->getBoundingBox ();

    items.erase (currentItem);

    currentItem = items.end ();


    redraw (bb);
}


void Editor::unselectCurrentItem ()
{
    ensureSelected ();


    currentItem->get ()->draw (gui, Gui::NORMAL);

    currentItem = items.end ();


    gui.endPaint ();
}


void Editor::addItem (SelectableGraphicsItem *item)
{
    items.emplace_back (item);

    select (--items.end ());
}


void Editor::select (Items::iterator item)
{
    gui.setDisplayable (false);


    if (currentItem != items.end ())
        unselectCurrentItem ();

    currentItem = item;

    if (currentItem != items.end ())
        currentItem->get ()->draw (gui, Gui::HIGHLIGHTED);


    gui.setDisplayable (true);

    gui.endPaint ();
}


void Editor::ensureSelected ()
{
    if (currentItem == items.end ())
        throw std::runtime_error ("item not selected");
}


void Editor::redraw (const Rect &invalidated)
{
    gui.beginPaint (invalidated);

    for (Items::const_iterator item = items.cbegin (); item != items.cend (); ++item)
        if (item->get ()->getBoundingBox () & invalidated)
            item->get ()->draw (gui, item == currentItem ? Gui::HIGHLIGHTED :
                                                           Gui::NORMAL);

    gui.endPaint ();
}


void Editor::ensureItemCreatorsRegistered ()
{
    static bool registered = false;

    if (registered)
        return;


    DocumentReader::registerItemCreator (Line::TITLE, &Line::fromContents);
    DocumentReader::registerItemCreator (Ellipse::TITLE, &Ellipse::fromContents);

    registered = true;
}


std::string Editor::getDocumentHeader ()
{
    std::string s = getCopyrightMsg ();

    s += ". Document header.";

    return s;
}


std::string Editor::getDocumentFooter ()
{
    std::string s = getCopyrightMsg ();

    s += ". Document footer.";

    return s;
}
