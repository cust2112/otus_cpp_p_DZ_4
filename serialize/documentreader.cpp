
#include <stdexcept>

#include "documentreader.h"


DocumentReader::ItemCreators DocumentReader::itemCreators;


DocumentReader::~DocumentReader () {
}


void DocumentReader::registerItemCreator (const std::string &itemTitle, ItemCreator itemCreator)
{
    std::pair <ItemCreators::iterator, bool> pr =
            itemCreators.insert (ItemCreators::value_type (itemTitle, itemCreator));

    if (!pr.second)
        throw std::runtime_error ("DocumentReader: item creator for title '" + itemTitle +
                              "' already registered");
}


Serializable *DocumentReader::readItem ()
{
    std::string title, contents;

    if (readItem (title, contents))
        return createItemFrom (title, contents);
    else
        return nullptr;
}


Serializable *DocumentReader::createItemFrom (const std::string &title, const std::string &contents)
{
    ItemCreators::const_iterator i = itemCreators.find (title);

    if (i == itemCreators.end ())
        throw std::runtime_error ("DocumentReader: item creator for title '" + title +
                              "' wasn't registered");


    return i->second (contents);
}
