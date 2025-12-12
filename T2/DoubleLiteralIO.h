#ifndef DOUBLE_LITERAL_IO_H
#define DOUBLE_LITERAl_IO_H
#include <istream>

namespace nabiullin
{
  struct DoubleLiteralIO
  {
    double& ref;
  };

  std::istream& operator>>(std::istream& in, DoubleLiteralIO&& dest);
}
#endif
