#ifndef DELIMETER_IO_H
#define DELIMETER_IO_H
#include <istream>

namespace nabiullin
{
  struct DelimeterIO
  {
    char exp;
  };

  std::istream& operator>>(std::istream& in, DelimeterIO&& dest);
}
#endif
