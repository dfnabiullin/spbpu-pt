#include "iofmtguard.h"

nabiullin::iofmtguard::iofmtguard(std::basic_ios< char >& s) : s_(s), fill_(s.fill()), fmt_(s.flags()) {}

nabiullin::iofmtguard::~iofmtguard()
{
  s_.fill(fill_);
  s_.flags(fmt_);
}
