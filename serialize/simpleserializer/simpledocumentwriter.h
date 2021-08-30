#ifndef SIMPLEDOCUMENTWRITER_H
#define SIMPLEDOCUMENTWRITER_H

#include <fstream>

#include "../documentwriter.h"


class SimpleDocumentWriter : public DocumentWriter {
public:
    explicit SimpleDocumentWriter (std::string fileName);
    ~SimpleDocumentWriter () override;

    void writeDocumentHeader (const std::string &header) override;
    void writeItem (const std::string &title, const std::string &contents) override;
    void writeDocumentFooter (const std::string &footer) override;


private:
    std::ofstream f;
};


#endif // SIMPLEDOCUMENTWRITER_H
