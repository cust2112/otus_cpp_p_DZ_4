#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "selectablegraphicsitem.h"


class Editor;


class Ellipse : public SelectableGraphicsItem {
public:
    static const std::string TITLE;

    static Serializable *fromContents (const std::string &contents);


    ~Ellipse () override;

    void setP2 (const Point &p2) override;
    Rect getBoundingBox () const override;

    void draw (Gui &gui, Gui::DrawStyle style = Gui::NORMAL) override;

    const std::string &getTitle () const override;
    std::string getContents () const override;

    Point getCenter () const override;


private:
    Point center;
    int a, b;

    friend class Editor;
    Ellipse (const Point &center) : center (center), a (0), b (0) {}
};


#endif // ELLIPSE_H
