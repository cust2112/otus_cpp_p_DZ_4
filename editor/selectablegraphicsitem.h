#ifndef SELECTABLEGRAPHICSITEM_H
#define SELECTABLEGRAPHICSITEM_H

#include "../common/point.h"
#include "serializablegraphicsitem.h"


class SelectableGraphicsItem : public SerializableGraphicsItem {
public:
    ~SelectableGraphicsItem () override {}

    virtual Point getCenter () const = 0;
};


#endif // SELECTABLEGRAPHICSITEM_H
