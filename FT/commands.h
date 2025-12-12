#ifndef COMMANDS_H
#define COMMANDS_H
#include <fstream>
#include <list>
#include <string>
#include <vector>
#include "Node.h"

namespace nabiullin
{
  void print(std::string&, std::vector< std::string >&, std::ostream&);
  void encode(std::string&, std::vector< std::string >&);
  void inspect(std::string&, std::vector< std::string >&, std::ostream&);
  void merge(std::string&, std::vector< std::string >&);
  void concat(std::string&, std::vector< std::string >&);
  void flush(std::string&, std::vector< std::string >&, std::ostream&);
  void read(std::string&, std::vector< std::string >&, std::istream&);
  void equals(std::string&, std::vector< std::string >&);
  void drop(std::string&, std::vector< std::string >&);
  void list(std::string&, std::vector< std::string >&, std::ostream&);
  bool boolInspect(std::string);
  bool boolEquals(std::string, std::string);
  void fillFrequencyTable(std::map< char, size_t >&, std::string, const size_t);
  void fillPriorityQueue(std::list< Node* >&, std::map< char, size_t >&);
  void fillEncodeTable(Node*, std::map< char, std::string >&, std::string&, size_t&);
  std::string encodeData(std::map< char, std::string >&, std::string);
}
#endif
