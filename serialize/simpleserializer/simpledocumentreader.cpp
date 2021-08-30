
#include <stdexcept>

#include "../../common/utils.h"
#include "simpledocumentreader.h"
#include "simpleserializerfactory.h"


SimpleDocumentReader::SimpleDocumentReader (std::string fileName)
{
    if (!endsWith (fileName, SimpleSerializerFactory::FILE_EXTENSION))
        fileName += SimpleSerializerFactory::FILE_EXTENSION;


    f.open (fileName);

    if (!f.is_open ())
        throw std::runtime_error ("Could not open '" + fileName + "'");
}


SimpleDocumentReader::~SimpleDocumentReader () {
}


void SimpleDocumentReader::readDocumentHeader (const std::string &header)
{
    std::getline (f, s);

    if (s != header)
        throw std::runtime_error ("Invalid document header: '" + header + "'");
}


void SimpleDocumentReader::readDocumentFooter (const std::string &footer)
{
    //std::getline (f, s);

    if (s != footer)
        throw std::runtime_error ("Invalid document footer: '" + footer + "'");
}


bool SimpleDocumentReader::readItem (std::string &title, std::string &contents)
{
    std::getline (f, s);

    if (s.size () == 0 || s[0] != '\t')
        return false;


    size_t tabPos = s.find ('\t', 1);

    title = std::string (s, 1, tabPos - 1);
    contents = std::string (s, tabPos + 1);

    return true;
}
