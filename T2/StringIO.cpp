#include "StringIO.h"
#include "DelimeterIO.h"

std::istream& nabiullin::operator>>(std::istream& in, StringIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  return std::getline(in >> DelimeterIO{'"'}, dest.ref, '"');
}
