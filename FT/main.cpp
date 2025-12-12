#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "commands.h"

namespace nabiullin
{
  void createData(std::vector< std::string >& data)
  {
    for (size_t i = 0; i < 10; i++)
    {
      data.push_back("");
    }
  }
  std::string getCommand(std::string& line)
  {
    size_t spaceIndex = line.find_first_of(' ', 0);
    std::string command = line.substr(0, spaceIndex);
    if (spaceIndex != line.npos)
    {
      spaceIndex++;
    }
    line.erase(0, spaceIndex);
    return command;
  }
}

int main()
{
  std::istream& cin = std::cin;
  std::ostream& cout = std::cout;
  std::vector< std::string > data;
  nabiullin::createData(data);
  std::map< std::string, std::function< void(std::string&) > > commands
  (
      {
          {"print", std::bind(nabiullin::print, std::placeholders::_1, std::ref(data), std::ref(cout))},
          {"encode", std::bind(nabiullin::encode, std::placeholders::_1, std::ref(data))},
          {"inspect", std::bind(nabiullin::inspect, std::placeholders::_1, std::ref(data), std::ref(cout))},
          {"merge", std::bind(nabiullin::merge, std::placeholders::_1, std::ref(data))},
          {"concat", std::bind(nabiullin::concat, std::placeholders::_1, std::ref(data))},
          {"flush", std::bind(nabiullin::flush, std::placeholders::_1, std::ref(data), std::ref(cout))},
          {"read", std::bind(nabiullin::read, std::placeholders::_1, std::ref(data), std::ref(cin))},
          {"equals", std::bind(nabiullin::equals, std::placeholders::_1, std::ref(data))},
          {"drop", std::bind(nabiullin::drop, std::placeholders::_1, std::ref(data))},
          {"list", std::bind(nabiullin::list, std::placeholders::_1, std::ref(data), std::ref(cout))}
      }
  );
  while (!cin.eof())
  {
    std::string command = "", line;
    std::getline(cin, line);
    command = nabiullin::getCommand(line);
    if (!command.empty())
    {
      auto command_iter = commands.find(command);
      command_iter->second(line);
    }
  }
  return 0;
}
