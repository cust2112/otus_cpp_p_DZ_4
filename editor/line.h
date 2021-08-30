#ifndef LINE_H
#define LINE_H

#include "selectablegraphicsitem.h"


class Editor;


class Line : public SelectableGraphicsItem {
public:
    static const std::string TITLE;

    static Serializable *fromContents (const std::string &contents);


    ~Line () override;

    void setP2 (const Point &p2) override;
    Rect getBoundingBox () const override;

    void draw (Gui &gui, Gui::DrawStyle style = Gui::NORMAL) override;

    const std::string &getTitle () const override;
    std::string getContents () const override;

    Point getCenter () const override;


private:
    Point p1, p2;

    friend class Editor;
    Line (const Point &p1) : p1 (p1), p2 (p1) {}
};


#endif // LINE_H
