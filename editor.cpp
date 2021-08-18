
#include "editor.h"
#include "gui.h"


Editor::Editor (Gui &gui)
{
    gui.setEditor (this);
}
