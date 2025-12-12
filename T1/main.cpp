#include <climits>
#include <iomanip>
#include <iostream>
#include <string>
#include "parallelogram.h"
#include "rectangle.h"
#include "square.h"

int main()
{
  unsigned short numberShapes = 0;
  std::unique_ptr< std::unique_ptr< nabiullin::Shape >[] > shapes(new std::unique_ptr< nabiullin::Shape >[USHRT_MAX]);
  std::string word = "";
  nabiullin::point_t scaleCenter;
  double scaleCoefficient = 0;
  while (!std::cin.eof() && std::cin >> word)
  {
    try
    {
      if (word == "RECTANGLE")
      {
        nabiullin::point_t valueLeftDown, valueRightUp;
        std::cin >> valueLeftDown.x >> valueLeftDown.y >> valueRightUp.x >> valueRightUp.y;
        shapes[numberShapes++] =
            std::unique_ptr< nabiullin::Shape >(new nabiullin::Rectangle(valueLeftDown, valueRightUp));
      }
      else if (word == "PARALLELOGRAM")
      {
        nabiullin::point_t valueFirstPoint, valueSecondPoint, valueThirdPoint;
        std::cin >> valueFirstPoint.x >> valueFirstPoint.y >> valueSecondPoint.x >> valueSecondPoint.y >>
            valueThirdPoint.x >> valueThirdPoint.y;
        shapes[numberShapes++] = std::unique_ptr< nabiullin::Shape >(
            new nabiullin::Parallelogram(valueFirstPoint, valueSecondPoint, valueThirdPoint));
      }
      else if (word == "SQUARE")
      {
        nabiullin::point_t valueLeftDown;
        double valueSide;
        std::cin >> valueLeftDown.x >> valueLeftDown.y >> valueSide;
        shapes[numberShapes++] = std::unique_ptr< nabiullin::Shape >(new nabiullin::Square(valueLeftDown, valueSide));
      }
      else if (word == "SCALE")
      {
        break;
      }
      else
      {
        std::cin.ignore(std::cin.rdbuf()->in_avail(), '\n');
      }
    } catch (const std::exception& e)
    {
      std::cerr << e.what();
    }
  }
  try
  {
    if (word != "SCALE")
    {
      throw std::invalid_argument("Error, the scaling command is not described, end of the program.\n");
    }
    else
    {
      std::cin >> scaleCenter.x >> scaleCenter.y >> scaleCoefficient;
    }
  } catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  try
  {
    if (numberShapes == 0)
    {
      throw std::invalid_argument("Error, nothing to scale, end of the program.\n");
    }
  } catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  double area = 0;
  for (int i = 0; i < numberShapes; i++)
  {
    area += shapes[i]->getArea();
  }
  std::cout << std::fixed << std::setprecision(1) << area << " ";
  for (int i = 0; i < numberShapes; i++)
  {
    std::cout << shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2 << " "
              << shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2 << " "
              << shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2 << " "
              << shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
    if (i != numberShapes - 1)
    {
      std::cout << " ";
    }
    else
    {
      std::cout << "\n";
    }
  }
  for (int i = 0; i < numberShapes; i++)
  {

    shapes[i]->move((shapes[i]->getFrameRect().pos.x - scaleCenter.x) * (scaleCoefficient - 1),
        (shapes[i]->getFrameRect().pos.y - scaleCenter.y) * (scaleCoefficient - 1));
    try
    {
      shapes[i]->scale(scaleCoefficient);
    } catch (const std::exception& e)
    {
      std::cerr << e.what();
      return 1;
    }
  }
  std::cout << area * scaleCoefficient * scaleCoefficient << " ";
  for (int i = 0; i < numberShapes; i++)
  {
    std::cout << shapes[i]->getFrameRect().pos.x - shapes[i]->getFrameRect().width / 2 << " "
              << shapes[i]->getFrameRect().pos.y - shapes[i]->getFrameRect().height / 2 << " "
              << shapes[i]->getFrameRect().pos.x + shapes[i]->getFrameRect().width / 2 << " "
              << shapes[i]->getFrameRect().pos.y + shapes[i]->getFrameRect().height / 2;
    if (i != numberShapes - 1)
    {
      std::cout << " ";
    }
    else
    {
      std::cout << "\n";
    }
  }
  return 0;
}
