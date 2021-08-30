#ifndef SIMPLESERIALIZERFACTORY_H
#define SIMPLESERIALIZERFACTORY_H

#include "../serializerfactory.h"


class SimpleSerializerFactory : public SerializerFactory {
public:
    static const std::string FILE_EXTENSION;

    DocReaderUPtr createDocumentReader (const std::string &fileName);
    DocWriterUPtr createDocumentWriter (const std::string &fileName);
};


#endif // SIMPLESERIALIZERFACTORY_H
