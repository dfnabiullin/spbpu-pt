#ifndef RATIONAL_LSP_IO_H
#define RATIONAL_LSP_IO_H
#include <istream>
#include <utility>

namespace nabiullin
{
  struct RationalLSPIO
  {
    std::pair< long long, unsigned long long >& ref;
  };

  std::istream& operator>>(std::istream& in, RationalLSPIO&& dest);
}
#endif
