#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <vector>
#include "commands.h"
#include "Node.h"

void nabiullin::print(std::string& line, std::vector< std::string >& data, std::ostream& cout)
{
  const size_t index = line[4] - '0';
  cout << data[index] << "\n";
}

void nabiullin::encode(std::string& line, std::vector< std::string >& data)
{
  const size_t indexFirst = line[4] - '0', indexSecond = line[10] - '0';
  std::string tempData = data[indexSecond], encodedChar = "";
  std::map< char, size_t > frequencyTable;
  std::list< Node* > priorityQueue;
  std::map< char, std::string > encodeTable;
  size_t level = 0;
  fillFrequencyTable(frequencyTable, tempData, indexSecond);
  fillPriorityQueue(priorityQueue, frequencyTable);
  fillEncodeTable(priorityQueue.front(), encodeTable, encodedChar, level);
  data[indexFirst] = encodeData(encodeTable, tempData);
}

void nabiullin::inspect(std::string& line, std::vector< std::string >& data, std::ostream& cout)
{
  const size_t index = line[4] - '0';
  std::string tempData = data[index];
  if (boolInspect(tempData))
  {
    cout << "ENCODED\n";
  }
  else
  {
    cout << "RAW\n";
  }
}

void nabiullin::merge(std::string& line, std::vector< std ::string >& data)
{
  const size_t indexFirst = line[10] - '0', indexSecond = line[16] - '0';
  std::string firstData = data[line[10] - '0'], secondData = data[line[16] - '0'];
  if ((boolInspect(firstData) == boolInspect(secondData)) && boolEquals(firstData, secondData))
  {
    concat(line, data);
  }
}

void nabiullin::concat(std::string& line, std::vector< std::string >& data)
{
  const size_t indexFirst = line[4] - '0', indexSecond = line[10] - '0', indexThird = line[16] - '0';
  data[indexFirst] = data[indexSecond] + data[indexThird];
}

void nabiullin::flush(std::string& line, std::vector< std::string >& data, std::ostream& cout)
{
  const size_t index = line[4] - '0';
  if (line.size() > 5)
  {
    line.erase(line.begin(), line.begin() + 6);
    std::ofstream out(line);
    out << data[index];
    out.close();
  }
  else
  {
    cout << data[index];
  }
}

void nabiullin::read(std::string& line, std::vector< std::string >& data, std::istream& cin)
{
  const size_t index = line[4] - '0';
  if (line.size() > 5)
  {
    line.erase(line.begin(), line.begin() + 6);
    std::ifstream in(line);
    in >> data[index];
    in.close();
  }
  else
  {
    cin >> data[index];
  }
}

void nabiullin::equals(std::string& line, std::vector< std::string >& data)
{
  const size_t indexFirst = line[4] - '0', indexSecond = line[10] - '0';
  std::string firstData = data[indexFirst], secondData = data[indexSecond];
  boolEquals(firstData, secondData);
}

void nabiullin::drop(std::string& line, std::vector< std::string >& data)
{
  const size_t index = line[4] - '0';
  data[index].erase();
}

void nabiullin::list(std::string& line, std::vector< std::string >& data, std::ostream& cout)
{
  for (size_t i = 0; i < data.size(); i++)
  {
    if (!data[i].empty())
    {

      cout << "data" << i << " ";
    }
  }
  cout << "\n";
}

bool nabiullin::boolInspect(std::string data)
{
  return data[0] >= '0' && data[0] <= '1';
}

bool nabiullin::boolEquals(std::string firstData, std::string secondData)
{
  return firstData == secondData;
}

void nabiullin::fillFrequencyTable(std::map< char, size_t >& frequencyTable, std::string data, const size_t index)
{
  for (size_t i = 0; i < data.size(); i++)
  {
    std::map< const char, size_t >::iterator it = frequencyTable.find(data[i]);
    if (it != frequencyTable.end())
    {
      it->second++;
    }
    else
    {
      frequencyTable.emplace(data[i], 1);
    }
  }
}

void nabiullin::fillPriorityQueue(std::list< Node* >& priorityQueue, std::map< char, size_t >& frequencyTable)
{
  for (std::map< char, size_t >::iterator it = frequencyTable.begin(); it != frequencyTable.end(); it++)
  {
    Node* node = new Node(it->first, it->second);
    priorityQueue.push_back(node);
  }
  while (priorityQueue.size() > 1)
  {
    priorityQueue.sort(sortNode);
    Node* left = priorityQueue.front();
    priorityQueue.pop_front();
    Node* right = priorityQueue.front();
    priorityQueue.pop_front();
    Node* root = new Node(left, right);
    priorityQueue.push_back(root);
  }
}

void nabiullin::fillEncodeTable(Node* node,
    std::map< char, std::string >& encodeTable,
    std::string& encodedChar,
    size_t& level)
{
  if (node->value_ == '\0')
  {
    level++;
    encodedChar += "0";
    fillEncodeTable(node->left_, encodeTable, encodedChar, level);
    encodedChar += "1";
    fillEncodeTable(node->right_, encodeTable, encodedChar, level);
  }
  else
  {
    char tempChar = node->value_;
    encodeTable.emplace(tempChar, encodedChar);
    encodedChar.erase(encodedChar.size() - level, level);
    level--;
  }
}

std::string nabiullin::encodeData(std::map< char, std::string >& encodeTable, std::string tempData)
{
  std::string encodeData = "";
  for (size_t i = 0; i < tempData.size(); i++)
  {
    encodeData += encodeTable.find(tempData[i])->second;
  }
  return encodeData;
}
