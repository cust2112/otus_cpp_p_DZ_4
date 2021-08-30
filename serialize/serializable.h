#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <string>


class Serializable {
public:
    virtual ~Serializable () {}

    virtual const std::string &getTitle () const = 0;
    virtual std::string getContents () const = 0;
};


#endif // SERIALIZABLE_H
