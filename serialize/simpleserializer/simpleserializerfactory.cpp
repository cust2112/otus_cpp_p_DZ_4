
#include "simpledocumentreader.h"
#include "simpledocumentwriter.h"
#include "simpleserializerfactory.h"


const std::string SimpleSerializerFactory::FILE_EXTENSION = ".ged";


DocReaderUPtr SimpleSerializerFactory::createDocumentReader (const std::string &fileName)
{
    return DocReaderUPtr (new SimpleDocumentReader (fileName));
}


DocWriterUPtr SimpleSerializerFactory::createDocumentWriter (const std::string &fileName)
{
    return DocWriterUPtr (new SimpleDocumentWriter (fileName));
}
