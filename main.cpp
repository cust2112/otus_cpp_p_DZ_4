
#include "common/utils.h"
#include "editor/editor.h"
#include "gui/textmodeui/textmodeui.h"


int main ()
{
    TextModeUI gui;
    Editor editor (gui);  USED_IMPLICITLY (editor);

    gui.startEventLoop ();

    return 0;
}
