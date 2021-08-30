#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>


typedef std::vector <std::string> Strings;


Strings splitArgs (const std::string &args, size_t argsSize);

int str2int (const std::string &s);

bool endsWith (const std::string &str, const std::string &substr);

#define UNUSED(x) (void) x

#define USED_IMPLICITLY(x)  UNUSED (x)


#endif // UTILS_H
