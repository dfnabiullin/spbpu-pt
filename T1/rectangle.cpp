#include <stdexcept>
#include "rectangle.h"

nabiullin::Rectangle::Rectangle(point_t valueLeftDown, point_t valueRightUp)
{
  if (valueLeftDown.x < valueRightUp.x && valueLeftDown.y < valueRightUp.y)
  {
    rec_t.width = valueRightUp.x - valueLeftDown.x;
    rec_t.height = valueRightUp.y - valueLeftDown.y;
    rec_t.pos.x = (valueRightUp.x + valueLeftDown.x) / 2;
    rec_t.pos.y = (valueRightUp.y + valueLeftDown.y) / 2;
  }
  else
  {
    throw std::invalid_argument("Errors in the description of supported shapes.\n");
  }
}

double nabiullin::Rectangle::getArea() const
{
  return rec_t.width * rec_t.height;
}

nabiullin::rectangle_t nabiullin::Rectangle::getFrameRect() const
{
  return rec_t;
}

void nabiullin::Rectangle::move(const point_t &point)
{
  rec_t.pos.x = point.x;
  rec_t.pos.y = point.y;
}

void nabiullin::Rectangle::move(double x, double y)
{
  rec_t.pos.x += x;
  rec_t.pos.y += y;
}

void nabiullin::Rectangle::doScale(double coefficient)
{
  rec_t.width *= coefficient;
  rec_t.height *= coefficient;
}
