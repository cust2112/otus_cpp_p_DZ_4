#ifndef DOCUMENTWRITER_H
#define DOCUMENTWRITER_H

#include <string>


class DocumentWriter {
public:
    virtual ~DocumentWriter () {}/*;*/

    virtual void writeDocumentHeader (const std::string &header) = 0;
    virtual void writeItem (const std::string &title, const std::string &contents) = 0;
    virtual void writeDocumentFooter (const std::string &footer) = 0;
};


#endif // DOCUMENTWRITER_H
