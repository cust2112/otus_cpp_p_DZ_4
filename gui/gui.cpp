
#include <stdexcept>

#include "gui.h"


Gui::Gui ()
    : displayable (true), editor (0) {
}


Gui::~Gui () {
}


void Gui::setEditor (Editor *editor)
{
    this->editor = editor;
}


Editor *Gui::getEditor ()
{
    if (!editor)
        throw std::logic_error ("Gui: editor not set");

    return editor;
}
