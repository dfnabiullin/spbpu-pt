#include <stdexcept>
#include "shape.h"

void nabiullin::Shape::scale(double coefficient)
{
  if (coefficient < 0)
  {
    throw std::invalid_argument("Error, the scaling command has an incorrect scaling factor, end of the program.\n");
  }
  else
  {
    doScale(coefficient);
  }
}
