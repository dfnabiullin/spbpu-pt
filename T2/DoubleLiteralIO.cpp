#include "DoubleLiteralIO.h"
#include "DelimeterIO.h"

std::istream& nabiullin::operator>>(std::istream& in, DoubleLiteralIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  return in >> dest.ref >> DelimeterIO{'d'};
}
