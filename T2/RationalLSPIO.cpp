#include "RationalLSPIO.h"
#include "DelimeterIO.h"

std::istream& nabiullin::operator>>(std::istream& in, RationalLSPIO&& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  return in >> DelimeterIO{'('} >> DelimeterIO{':'} >> DelimeterIO{'N'} >> dest.ref.first >> DelimeterIO{':'}
            >> DelimeterIO{'D'} >> dest.ref.second >> DelimeterIO{':'} >> DelimeterIO{')'};
}
