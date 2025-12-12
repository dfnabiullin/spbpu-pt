#include <stdexcept>
#include "square.h"

nabiullin::Square::Square(point_t valueLeftDown, double valueSide)
{
  if (valueSide > 0)
  {
    leftDown.x = valueLeftDown.x;
    leftDown.y = valueLeftDown.y;
    side = valueSide;
  }
  else
  {
    throw std::invalid_argument("Errors in the description of supported shapes.\n");
  }
}

double nabiullin::Square::getArea() const
{
  return side * side;
}

nabiullin::rectangle_t nabiullin::Square::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = side;
  frameRect.height = side;
  frameRect.pos.x = leftDown.x + (side / 2);
  frameRect.pos.y = leftDown.y + (side / 2);
  return frameRect;
}

void nabiullin::Square::move(const point_t &point)
{
  leftDown.x = point.x - (side / 2);
  leftDown.y = point.y - (side / 2);
}

void nabiullin::Square::move(double x, double y)
{
  leftDown.x += x;
  leftDown.y += y;
}

void nabiullin::Square::doScale(double coefficient)
{
  point_t center;
  center.x = leftDown.x + (side / 2);
  center.y = leftDown.y + (side / 2);
  side *= coefficient;
  leftDown.x = center.x - (side / 2);
  leftDown.y = center.y - (side / 2);
}
