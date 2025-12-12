#include <algorithm>
#include <stdexcept>
#include "parallelogram.h"

nabiullin::Parallelogram::Parallelogram(point_t valueFirstPoint, point_t valueSecondPoint, point_t valueThirdPoint)
{
  if (valueFirstPoint.x > valueSecondPoint.x || valueFirstPoint.y > valueSecondPoint.y)
  {
    std::swap(valueFirstPoint.x, valueSecondPoint.x);
    std::swap(valueFirstPoint.y, valueSecondPoint.y);
  }
  if (valueFirstPoint.x > valueThirdPoint.x || valueFirstPoint.y > valueThirdPoint.y)
  {
    std::swap(valueFirstPoint.x, valueThirdPoint.x);
    std::swap(valueFirstPoint.y, valueThirdPoint.y);
  }
  if (valueThirdPoint.x < valueSecondPoint.x || valueThirdPoint.y < valueSecondPoint.y)
  {
    std::swap(valueThirdPoint.x, valueSecondPoint.x);
    std::swap(valueThirdPoint.y, valueSecondPoint.y);
  }
  if ((valueFirstPoint.x != valueSecondPoint.x || valueFirstPoint.y != valueSecondPoint.y) &&
      (valueFirstPoint.x != valueThirdPoint.x || valueFirstPoint.y != valueThirdPoint.y) &&
      (valueSecondPoint.x != valueThirdPoint.x || valueSecondPoint.y != valueThirdPoint.y) &&
      (valueFirstPoint.y == valueSecondPoint.y || valueSecondPoint.y == valueThirdPoint.y))
  {
    firstPoint = valueFirstPoint;
    secondPoint = valueSecondPoint;
    thirdPoint = valueThirdPoint;
  }
  else
  {
    throw std::invalid_argument("Errors in the description of supported shapes.\n");
  }
}

double nabiullin::Parallelogram::getArea() const
{
  if (firstPoint.y == secondPoint.y)
  {
    return (secondPoint.x - firstPoint.x) * (thirdPoint.y - firstPoint.y);
  }
  else
  {
    return (thirdPoint.x - secondPoint.x) * (thirdPoint.y - firstPoint.y);
  }
}

nabiullin::rectangle_t nabiullin::Parallelogram::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = thirdPoint.x - firstPoint.x;
  frameRect.height = thirdPoint.y - firstPoint.y;
  frameRect.pos.x = (thirdPoint.x + firstPoint.x) / 2;
  frameRect.pos.y = (thirdPoint.y + firstPoint.y) / 2;
  return frameRect;
}

void nabiullin::Parallelogram::move(const point_t &point)
{
  point_t center;
  center.x = (thirdPoint.x + firstPoint.x) / 2;
  center.y = (thirdPoint.y + firstPoint.y) / 2;
  firstPoint.x += point.x - center.x;
  firstPoint.y += point.y - center.y;
  secondPoint.x += point.x - center.x;
  secondPoint.y += point.y - center.y;
  thirdPoint.x += point.x - center.x;
  thirdPoint.y += point.y - center.y;
}

void nabiullin::Parallelogram::move(double x, double y)
{
  firstPoint.x += x;
  firstPoint.y += y;
  secondPoint.x += x;
  secondPoint.y += y;
  thirdPoint.x += x;
  thirdPoint.y += y;
}

void nabiullin::Parallelogram::doScale(double coefficient)
{
  double halfSideX = (thirdPoint.x - firstPoint.x) / 2, halfSideY = (thirdPoint.y - firstPoint.y) / 2;
  point_t center;
  center.x = thirdPoint.x - halfSideX;
  center.y = thirdPoint.y - halfSideY;
  halfSideX *= coefficient;
  halfSideY *= coefficient;
  thirdPoint.x = center.x + halfSideX;
  thirdPoint.y = center.y + halfSideY;
  firstPoint.x = center.x - halfSideX;
  firstPoint.y = center.y - halfSideY;
}
