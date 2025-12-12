#ifndef STRING_IO_H
#define STRING_IO_H
#include <istream>
#include <string>

namespace nabiullin
{
  struct StringIO
  {
    std::string& ref;
  };

  std::istream& operator>>(std::istream& in, StringIO&& dest);
}
#endif
