
#include <stdexcept>

#include "../../common/utils.h"
#include "simpledocumentwriter.h"
#include "simpleserializerfactory.h"


SimpleDocumentWriter::SimpleDocumentWriter (std::string fileName)
{
    if (!endsWith (fileName, SimpleSerializerFactory::FILE_EXTENSION))
        fileName += SimpleSerializerFactory::FILE_EXTENSION;


    f.open (fileName);

    if (!f.is_open ())
        throw std::runtime_error ("Could not open '" + fileName + "'");
}


SimpleDocumentWriter::~SimpleDocumentWriter () {
}


void SimpleDocumentWriter::writeDocumentHeader (const std::string &header)
{
    f << header << std::endl;
}


void SimpleDocumentWriter::writeItem (const std::string &title, const std::string &contents)
{
    f << '\t' << title << '\t' << contents << std::endl;
}

void SimpleDocumentWriter::writeDocumentFooter (const std::string &footer)
{
    f << footer << std::endl;
}
