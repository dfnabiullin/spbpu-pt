#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

namespace nabiullin
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &point) = 0;
    virtual void move(double x, double y) = 0;
    void scale(double coefficient);

  private:
    virtual void doScale(double coefficient) = 0;
  };
};
#endif
