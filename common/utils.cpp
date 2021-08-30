
#include <algorithm>
#include <sstream>
#include <stdexcept>

#include "utils.h"


bool str2int (int &i, char const *s)
{
    char              c;
    std::stringstream ss(s);
    ss >> i;
    if (ss.fail() || ss.get(c)) {
        // not an integer
        return false;
    }
    return true;
}


Strings split (const std::string &s, char delim)
{
  std::stringstream ss (s);
  std::string item;
  std::vector<std::string> elems;

  elems.reserve (std::count (s.begin (), s.end (), delim) + 1);


  while (std::getline (ss, item, delim)) {
    // elems.push_back(item);
    elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
  }


  return elems;
}


Strings splitArgs (const std::string &args, size_t argsSize)
{
    Strings argList = split (args, ' ');

    if (argList.size () == 1 && argList[0].size () == 0)  // empty args means 0 args
        argList.clear ();


    if (argList.size () != argsSize) {

        std::stringstream ss;

        ss << "incorrect number of arguments (must be " << argsSize << ")";

        throw std::runtime_error (ss.str ());
    }


    return argList;
}


int str2int (const std::string &s)
{
    int i;

    if (!str2int (i, s.c_str ()))
        throw std::runtime_error ("str2int conversion of '" + s + "' failed");


    return i;
}


bool endsWith (const std::string &str, const std::string &substr)
{
    return str.find (substr, str.length () - substr.length ()) != std::string::npos;
}
