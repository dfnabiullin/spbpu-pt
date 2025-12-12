#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

namespace nabiullin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t valueLeftDown, point_t valueRightUp);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double x, double y) override;

  private:
    rectangle_t rec_t;
    void doScale(double coefficient) override;
  };
}
#endif
