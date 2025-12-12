#include "DataStruct.h"
#include <iomanip>
#include <iosfwd>
#include "DelimeterIO.h"
#include "DoubleLiteralIO.h"
#include "RationalLSPIO.h"
#include "StringIO.h"
#include "iofmtguard.h"

std::istream& nabiullin::operator>>(std::istream& in, DataStruct& dest)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  nabiullin::DataStruct input;
  {
    using sep = DelimeterIO;
    using dbllit = DoubleLiteralIO;
    using ratlsp = RationalLSPIO;
    using str = StringIO;
    in >> sep{'('} >> sep{':'};
    for (unsigned short i = 0; i < 3; i++)
    {
      in >> sep{'k'} >> sep{'e'} >> sep{'y'};
      unsigned short number = 0;
      in >> number;
      if (number == 1)
      {
        in >> dbllit{input.key1} >> sep{':'};
      }
      if (number == 2)
      {
        in >> ratlsp{input.key2} >> sep{':'};
      }
      if (number == 3)
      {
        in >> str{input.key3} >> sep{':'};
      }
    }
    in >> sep{')'};
  }
  if (in)
  {
    dest = input;
  }
  return in;
}

std::ostream& nabiullin::operator<<(std::ostream& out, const DataStruct& src)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  iofmtguard fmtguard(out);
  out << "(:";
  out << "key1 " << std::fixed << std::setprecision(1) << src.key1 << "d:";
  out << "key2 (:N " << src.key2.first << ":D " << src.key2.second << ":):";
  out << "key3 \"" << src.key3 << "\":";
  out << ")";
  return out;
}

bool nabiullin::operator<(const DataStruct& first, const DataStruct& second)
{
  if (first.key1 == second.key1)
  {
    if (first.key2 == second.key2)
    {
      return (first.key3.length() < second.key3.length());
    }
    return first.key2 < second.key2;
  }
  return first.key1 < second.key1;
}
