
#include "editor.h"
#include "gui.h"


int main ()
{
    Gui gui;
    Editor editor (gui);


    gui.startEventLoop ();


    return 0;
}
