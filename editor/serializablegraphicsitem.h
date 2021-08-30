#ifndef SERIALIZABLEGRAPHICSITEM_H
#define SERIALIZABLEGRAPHICSITEM_H

#include <string>

#include "../serialize/serializable.h"
#include "graphicsitem.h"


class SerializableGraphicsItem : public GraphicsItem, public Serializable {
public:
    ~SerializableGraphicsItem () override {}
};


#endif // SERIALIZABLEGRAPHICSITEM_H
