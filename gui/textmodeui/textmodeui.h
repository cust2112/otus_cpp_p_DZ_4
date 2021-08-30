#ifndef TEXTMODEUI_H
#define TEXTMODEUI_H

#include <map>
#include <string>

#include "../gui.h"
#include "textmodecanvas.h"


class TextModeUI : public Gui {
public:
    TextModeUI ();
    ~TextModeUI () override;

    void startEventLoop () override;

    void beginPaint (const Rect &invalidated) override;
    void drawLine (const Point &p1, const Point &p2,
                   Gui::DrawStyle style = Gui::NORMAL) override;
    void drawEllipse (const Point &center, int a, int b,
                      Gui::DrawStyle style = Gui::NORMAL) override;
    void endPaint () override;

    Rect getViewPort () override;


private:
    typedef void (TextModeUI::*CmdHandler) (const std::string &);
    typedef std::map <std::string, CmdHandler> CmdHandlers;

    CmdHandlers cmdHandlers;
    TextModeCanvas cnv;


    void addLine (const std::string &args);
    void addEllipse (const std::string &args);
    void selectItemNearest2 (const std::string &args);
    void deleteSelectedItem (const std::string &args);
    void loadDocument (const std::string &args);
    void saveDocument (const std::string &args);
    void refreshDisplay  (const std::string &args);
    void printHelpMsg (const std::string &args = std::string ());

    std::string getline ();
    void splitIntoKeywordAndArgs (const std::string &cmd, std::string &keyword, std::string &args);
    void processCommand (const std::string &cmd);
};


#endif // TEXTMODEUI_H
