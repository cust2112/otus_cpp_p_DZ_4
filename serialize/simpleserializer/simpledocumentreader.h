#ifndef SIMPLEDOCUMENTREADER_H
#define SIMPLEDOCUMENTREADER_H

#include <fstream>

#include "../documentreader.h"


class SimpleDocumentReader : public DocumentReader {
public:
    explicit SimpleDocumentReader (std::string fileName);
    ~SimpleDocumentReader () override;

    void readDocumentHeader (const std::string &header) override;
    void readDocumentFooter (const std::string &footer) override;


protected:
    bool readItem (std::string &title, std::string &contents) override;


private:
    std::ifstream f;
    std::string s;
};


#endif // SIMPLEDOCUMENTREADER_H
