#ifndef DOCUMENTREADER_H
#define DOCUMENTREADER_H

#include <map>

#include "serializable.h"


class DocumentReader {
public:
    virtual ~DocumentReader ();


    typedef Serializable *(*ItemCreator) (const std::string &contents);

    static void registerItemCreator (const std::string &itemTitle, ItemCreator itemCreator);


    virtual void readDocumentHeader (const std::string &header) = 0;
    Serializable *readItem ();
    virtual void readDocumentFooter (const std::string &footer) = 0;


protected:
    virtual bool readItem (std::string &title, std::string &contents) = 0;

    Serializable *createItemFrom (const std::string &title, const std::string &contents);


private:
    typedef std::map <std::string, ItemCreator> ItemCreators;

    static ItemCreators itemCreators;
};


#endif // DOCUMENTREADER_H
