#ifndef SERIALIZERFACTORY_H
#define SERIALIZERFACTORY_H

#include <memory>

#include "documentreader.h"
#include "documentwriter.h"


typedef std::unique_ptr <DocumentReader> DocReaderUPtr;
typedef std::unique_ptr <DocumentWriter> DocWriterUPtr;


class SerializerFactory {
public:
    virtual DocReaderUPtr createDocumentReader (const std::string &fileName) = 0;
    virtual DocWriterUPtr createDocumentWriter (const std::string &fileName) = 0;
};


typedef std::unique_ptr <SerializerFactory> SerializerFactoryUPtr;


#endif // SERIALIZERFACTORY_H
