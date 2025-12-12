#ifndef SQUARE_H
#define SQUARE_H
#include "shape.h"

namespace nabiullin
{
  class Square : public Shape
  {
  public:
    Square(point_t valueLeftDown, double valueSide);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &point) override;
    void move(double x, double y) override;

  private:
    point_t leftDown;
    double side;
    void doScale(double coefficient) override;
  };
}
#endif
