#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "shape.h"

namespace nabiullin
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t valueFirstPoint, point_t valueSecondPoint, point_t valueThirdPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double x, double y) override;

  private:
    point_t firstPoint, secondPoint, thirdPoint;
    void doScale(double coefficient) override;
  };
}
#endif
